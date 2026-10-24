"""Assemble recovered sources independently, then compare with the original program.
usage: verify_source.py ROM [--ca65 PATH] [--ld65 PATH] [--json OUT]
No reference bytes are used as assembly inputs. Temporary binaries are discarded.
"""
import argparse,bisect,collections,concurrent.futures,hashlib,json,pathlib,re,subprocess,tempfile
import romio
import spc_audio_initialization_source
import decoded_source_references

ROOT = pathlib.Path(__file__).resolve().parent.parent


def spc_source(text):
    def bit_operand(match):
        address,bit = int(match[1],16),int(match[2])
        if not (address<0x2000): raise AssertionError('SPC bit operands contain a13-bit address')
        return f'${address|bit<<13:04X}'
    lines = (line.split(';',1)[0].strip() for line in text.splitlines())
    return '\n'.join(re.sub(r'\$([0-9A-Fa-f]{4})\.([0-7])',bit_operand,line)
                     if line.strip().split(' ',1)[0] in ('NOT1','MOV1','OR1','AND1','EOR1') else line
                     for line in lines)


def _overlap_quadratic(intervals):
    """Reference predicate (the original per-block scan); used only for degenerate negative sizes."""
    for index,(address,end) in enumerate(intervals):
        if not all(end<=left or address>=right for left,right in intervals[:index]):
            return index
    return None


def _has_overlap(intervals):
    """True when any pair satisfies the original conflict test: a1<b2 and a2<b1 (half-open, zero length allowed)."""
    spans = sorted((a,b) for a,b in intervals if b>a)
    cursor = None
    for a,b in spans:
        if cursor is not None and a<cursor:
            return True
        cursor = b if cursor is None else max(cursor,b)
    if len(spans)!=len(intervals):
        starts = [a for a,_ in spans]
        ends = [b for _,b in spans]
        for point in {a for a,b in intervals if b==a}:
            position = bisect.bisect_left(starts,point)-1
            if position>=0 and point<ends[position]:
                return True
    return False


def first_overlap_index(intervals):
    """Smallest k such that interval k conflicts with an earlier one (as the original scan reported), else None.

    One sorted sweep decides the common no-overlap case; a failing manifest bisects the monotone prefix predicate.
    """
    if any(b<a for a,b in intervals):
        return _overlap_quadratic(intervals)
    if not _has_overlap(intervals):
        return None
    low,high = 0,len(intervals)-1
    while low<high:
        middle = (low+high)//2
        if _has_overlap(intervals[:middle+1]): high = middle
        else: low = middle+1
    return low


def _plan_overlaps(blocks):
    """Return (raw_fail, rom_fail): manifest indices where the original loop's two overlap asserts first fire."""
    raw,rom,rom_index = [],[],[]
    for index,block in enumerate(blocks):
        try:
            address,size = int(block['address'],16),block['size']
            if not isinstance(size,int): break
        except (KeyError,ValueError,TypeError):
            break
        raw.append((address,address+size))
        reference = block.get('reference')
        if reference is None: break
        if reference=='rom':
            physical = address & 0x3FFFFF
            rom.append((physical,physical+size))
            rom_index.append(index)
    raw_fail = first_overlap_index(raw)
    rom_fail = first_overlap_index(rom)
    return raw_fail, (None if rom_fail is None else rom_index[rom_fail])


def _ordered(function,items,jobs):
    """Yield function(item) in input order; with jobs>1 run a bounded window of calls on threads.

    An exception raised while producing items surfaces only after every earlier item has been yielded.
    """
    if jobs<=1:
        for item in items: yield function(item)
        return
    window = collections.deque()
    iterator = iter(items)
    pending_error = None
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as pool:
        try:
            while True:
                try: item = next(iterator)
                except StopIteration: break
                except BaseException as error:
                    pending_error = error
                    break
                window.append(pool.submit(function,item))
                if len(window)>=jobs*4: yield window.popleft().result()
            while window: yield window.popleft().result()
        finally:
            for future in window: future.cancel()
    if pending_error is not None: raise pending_error


def verify(rom,ca65,ld65,manifest_path=None,jobs=1):
    manifest_path = ROOT/'src/manifest.json' if manifest_path is None else pathlib.Path(manifest_path)
    manifest = json.loads(manifest_path.read_text())
    decoded_images = decoded_source_references.images(rom, manifest)
    resources = decoded_source_references.declarations(manifest)
    blocks = []
    components = []
    with tempfile.TemporaryDirectory(prefix='som-source-') as temporary:
        directory = pathlib.Path(temporary)
        raw_fail,rom_fail = _plan_overlaps(manifest['blocks'])

        def prepared():
            for index,block in enumerate(manifest['blocks']):
                block['source'],int(block['address'],16),block['size']
                decoded_source_references.check_block(block, resources)
                if not (index!=raw_fail): raise AssertionError('overlapping source blocks')
                block['reference']
                if not (index!=rom_fail): raise AssertionError('overlapping physical ROM sources or mirrors')
                yield index,block

        def build(item):
            index,block = item
            source = ROOT/block['source']
            address,size = int(block['address'],16),block['size']
            start = address&65535
            obj,binary,config = (directory/f'{index}.{extension}' for extension in ('o','bin','cfg'))
            architecture = block.get('architecture','65816')
            if not (architecture in ('65816','spc700')): raise AssertionError(architecture)
            if architecture=='spc700':
                if not (block['reference']=='rom'): raise AssertionError()
                rebuilt = spc_audio_initialization_source.assemble(int(block['assembly_address'],16),spc_source(source.read_text()))
            else:
                config.write_text('MEMORY { PART: start = $%04X, size = $%04X, file = %%O; }\nSEGMENTS { CODE: load = PART, type = ro, optional = yes; RODATA: load = PART, type = ro, optional = yes; }\n' % (start,size))
                subprocess.run([ca65,'-I',str(ROOT),str(source),'-o',str(obj)],check=True)
                subprocess.run([ld65,'-C',str(config),str(obj),'-o',str(binary)],check=True)
                rebuilt = binary.read_bytes()
            reference = (rom[(address&0x3FFFFF):(address&0x3FFFFF)+size]
                         if block['reference']=='rom' else bytes(decoded_images[block['reference']][start:start+size]))
            if not (len(rebuilt)==size): raise AssertionError((source,'incorrect assembled length',len(rebuilt),size))
            if rebuilt!=reference:
                offset = next(i for i,(a,b) in enumerate(zip(rebuilt,reference)) if a!=b)
                raise AssertionError((source,f'byte mismatch at {address+offset:06X}',rebuilt[offset],reference[offset]))
            return block|dict(verified=True,source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),assembled_sha256=hashlib.sha256(rebuilt).hexdigest())

        for record in _ordered(build,prepared(),jobs):
            blocks.append(record)
        by_address = collections.defaultdict(list)
        for position,record in enumerate(blocks): by_address[record['address']].append(position)
        for component in manifest.get('components',[]):
            wanted = set(component['blocks'])
            selected = sorted((blocks[i] for i in sorted(i for address in wanted for i in by_address.get(address,()))),key=lambda b:int(b['address'],16))
            if not (len(selected)==len(component['blocks'])): raise AssertionError()
            address,size = int(component['address'],16),component['size']
            cursor = address
            architecture = component.get('architecture','65816')
            if not (architecture in ('65816','spc700')): raise AssertionError()
            assembly_cursor = int(component['assembly_address'],16) if architecture=='spc700' else None
            lines = []
            for index,block in enumerate(selected):
                if not (block.get('architecture','65816')==architecture): raise AssertionError('mixed component architectures')
                if not (int(block['address'],16)==cursor): raise AssertionError('component contains a gap')
                cursor += block['size']
                if architecture=='spc700':
                    if not (int(block['assembly_address'],16)==assembly_cursor): raise AssertionError('SPC component contains a native gap')
                    assembly_cursor += block['size']
                    text = spc_source((ROOT/block['source']).read_text())
                    labels = set(re.findall(r'^([A-Za-z_][A-Za-z_0-9]*):',text,re.M))
                    text = re.sub(r'\b[A-Za-z_][A-Za-z_0-9]*\b',
                                  lambda match: f'part_{index}_{match[0]}' if match[0] in labels else match[0],text)
                    lines.append(text)
                else:
                    lines += [f'.scope part_{index}', '.include '+json.dumps(block['source']), '.endscope']
            if not (cursor==address+size and component['reference']=='rom'): raise AssertionError()
            if architecture=='spc700':
                rebuilt = spc_audio_initialization_source.assemble(int(component['assembly_address'],16),'\n'.join(lines))
            else:
                source,obj,binary,config = (directory/f"component.{extension}" for extension in ('s','o','bin','cfg'))
                source.write_text('\n'.join(lines)+'\n')
                config.write_text('MEMORY { PART: start = $%04X, size = $%04X, file = %%O; }\nSEGMENTS { CODE: load = PART, type = ro, optional = yes; RODATA: load = PART, type = ro, optional = yes; }\n' % (address&65535,size))
                subprocess.run([ca65,'-I',str(ROOT),str(source),'-o',str(obj)],check=True)
                subprocess.run([ld65,'-C',str(config),str(obj),'-o',str(binary)],check=True)
                rebuilt = binary.read_bytes()
            if not (rebuilt==rom[(address&0x3FFFFF):(address&0x3FFFFF)+size]): raise AssertionError('integrated component mismatch')
            components.append(component|dict(verified=True,assembled_sha256=hashlib.sha256(rebuilt).hexdigest()))
    return dict(verified=True,rom_sha256=hashlib.sha256(rom).hexdigest(),manifest_sha256=hashlib.sha256(manifest_path.read_bytes()).hexdigest(),blocks=blocks,components=components,matching_source_bytes=sum(b['size'] for b in blocks),matching_instruction_source_bytes=sum(b['size'] for b in blocks if b.get('kind','code')!='data'),matching_65816_instruction_source_bytes=sum(b['size'] for b in blocks if b.get('kind','code')!='data' and b.get('architecture','65816')=='65816'),matching_spc_instruction_source_bytes=sum(b['size'] for b in blocks if b.get('kind','code')!='data' and b.get('architecture')=='spc700'),matching_data_source_bytes=sum(b['size'] for b in blocks if b.get('kind')=='data'),matching_ram_source_bytes=sum(b['size'] for b in blocks if b['reference']!='rom'),matching_rom_source_bytes=sum(b['size'] for b in blocks if b['reference']=='rom'),complete_rom_rebuild=False,full_code_decompilation_percent=None,scope='Independently assembled 65816 and SPC700 code and typed data match original ROM or declared decompressed resources exactly. SPC assembly addresses are distinct from physical ROM source addresses. RAM bytes are not a ROM-coverage numerator; full program reconstruction remains incomplete.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('rom')
    parser.add_argument('--ca65',default='ca65')
    parser.add_argument('--ld65',default='ld65')
    parser.add_argument('--json')
    parser.add_argument('--jobs',type=int,default=1,help='parallel ca65/ld65 workers; verdicts and report are identical to --jobs 1')
    args = parser.parse_args()
    report = verify(romio.load(args.rom),args.ca65,args.ld65,jobs=args.jobs)
    if args.json: pathlib.Path(args.json).write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({key:value for key,value in report.items() if key!='blocks'},indent=2))

if __name__=='__main__': main()
