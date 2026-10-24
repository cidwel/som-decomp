"""Audited ROM coverage: union of documented fields and verified compressed blocks.
usage: rom_progress.py ROM [--write]
This is a lower bound on documented ROM coverage, not a full decompilation percentage.
Use --refresh-audit-cache for a full inventory/native verification and cache refresh.
Use --reuse-audited-regions to reuse intact audited regions and check new source bytes.
"""
import sys, os, json, hashlib, romio, boot_decode, boot_audio, map_tables, map_piece_regions, map_asset_regions, script_regions
import dispatch_tables, boot_coefficients, map_tile_streams

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def build(rom, reuse_audited_regions=False):
    regions = []
    documented = bytearray(len(rom))
    verified = bytearray(len(rom))
    def add(name, start, count, stride, fields, evidence, status='documented'):
        region = {'name': name, 'offset': start, 'count': count, 'stride': stride,
                  'fields': [{'name': key, 'offset': off, 'size': width} for key, off, width in fields],
                  'status': status, 'evidence': evidence}
        regions.append(region)
        for row in range(count):
            for _, off, width in fields:
                lo = start + row * stride + off
                hi = lo + width
                assert 0 <= lo < hi <= len(rom)
                documented[lo:hi] = b'\x01' * width
                if status == 'verified': verified[lo:hi] = b'\x01' * width
    def table(filename, key, start, stride, fields):
        data = json.load(open(os.path.join(ROOT, 'data', filename)))
        rows = data[key]
        for i, row in enumerate(rows):
            assert row['id'] == i
            for name, off, width in fields:
                actual = int.from_bytes(rom[start + i * stride + off:start + i * stride + off + width], 'little')
                assert actual == row[name], (filename, i, name)
        add(filename, start, len(rows), stride, fields, ['data/' + filename, 'tools/dump_tables.py'])
        return data
    if reuse_audited_regions:
        from rom_progress_cache import load
        for region in load(rom):
            add(region['name'], region['offset'], region['count'], region['stride'],
                [(field['name'], field['offset'], field['size']) for field in region['fields']],
                region['evidence'], region['status'])
    else:
        mons = table('monsters.json', 'records', 0x101C00, 29,
                    [('level',0,1),('hp',1,2),('mp',3,1),('str',4,1),('agi',5,1),('int',6,1),
                     ('wis',7,1),('eva',8,1),('defense',9,2),('mev',11,1),('mdef',12,2),
                     ('type',14,1),('element',15,1),('exp',16,2),('spell_power_int',18,1),
                     ('spell_power_wis',19,1),('status_immunity',20,2),('weapon_a',23,1),
                     ('weapon_b',24,1),('gold',27,2)])
        for i, row in enumerate(mons['records']):
            assert list(rom[0x103A50 + i*5:0x103A50 + i*5 + 5]) == row['drop_row']
            assert rom[0x101C00+i*29+26] == row['weapon_level']*16 + row['magic_level']
        add('monster level nibbles',0x101C1A,128,29,[('weapon/magic levels',0,1)],['data/monsters.json'])
        add('monster drop rows',0x103A50,128,5,[('drop row',0,5)],['data/monsters.json','docs/rom-combat.md'])
        table('weapons.json','rows',0x101000,12,[('type',0,1),('stat_a',1,1),('stat_b',2,1),
              ('enemy_type_mask',5,1),('crit',6,1),('hit',7,1),('power',8,1),('status',9,2),('status_chance',11,1)])
        table('armors.json','rows',0x103ED0,10,[('flags',0,1),('defense',1,1),('evade',2,1),
              ('mdef',3,1),('mev',4,1),('equip_mask',5,1),('element_resist',6,1),('status_immunity',7,2)])
        spells = table('spells.json','rows',0x102AD0,64,[('target_flags',8,1),('power',10,1),
                       ('accuracy',11,1),('element',12,1),('status',13,2),('mp_cost',15,1)])
        for i,row in enumerate(spells['rows']):
            assert int.from_bytes(rom[0x8E801+i*2:0x8E803+i*2],'little') == row['handler']
        add('spell handler pointers',0x8E801,42,2,[('handler',0,2)],['data/spells.json'])
        table('boss_attacks.json','rows',0x10BDC1,7,[('flags',0,2),('accuracy',2,1),('power',3,1),
                       ('status',4,2),('status_chance',6,1)])
        table('items.json','rows',0x104152,16,[('effect_value',0,1)])
        levels = json.load(open(os.path.join(ROOT,'data/hero_levels.json')))
        for h,name in enumerate(('boy','girl','sprite')):
            start = 0x104210+h*0x318
            for i,row in enumerate(levels['heroes'][name]):
                at = start+i*8
                assert row == [int.from_bytes(rom[at:at+2],'little')] + list(rom[at+2:at+8])
            add(name+' level records',start,99,8,[('HP and six byte stats',0,8)],['data/hero_levels.json'])
        for i,value in enumerate(levels['exp_to_next']):
            assert int.from_bytes(rom[0x104B58+i*3:0x104B5B+i*3],'little') == value
        add('experience thresholds',0x104B58,99,3,[('experience',0,3)],['data/hero_levels.json'])
        maps = map_tables.Tables(rom)
        for name,base in (('map object pointers',0x87000),('map piece pointers',0x85000),('map event pointers',0x84000)):
            add(name,base,512,2,[('bank C8 offset',0,2)],['tools/map_tables.py','docs/maps.md'])
        add('map transitions',0x83000,1024,4,[('map, coordinates, layer and exit flags',0,4)],
            ['tools/map_tables.py','docs/maps.md'])
        for m in range(511):
            if maps.header(m) is None: continue
            first,last = maps.obj_ptr(m),maps.obj_ptr(m+1)
            assert last >= first+8 and (last-first-8)%8 == 0
            objects = maps.objects(m)
            assert len(objects)*8 == last-first-8
            add('map %d header and objects'%m,0x80000+first,1,last-first,
                [('header and 8-byte objects',0,last-first)],['tools/map_tables.py','docs/maps.md'])
            first,last = maps.event_ptr(m),maps.event_ptr(m+1)
            assert last >= first and (last-first)%2 == 0
            assert len(maps.events(m))*2 == last-first
            if last > first:
                add('map %d event references'%m,0x80000+first,(last-first)//2,2,[('event id',0,2)],
                    ['tools/map_tables.py','docs/maps.md'])
            first,last = maps.piece_ptr(m),maps.piece_ptr(m+1)
            pieces = maps.pieces(m)
            assert sum(5+(row['prefix'] is not None) for row in pieces) == last-first
            if last > first:
                add('map %d piece references'%m,0x80000+first,1,last-first,[('piece list',0,last-first)],
                    ['tools/map_tables.py','docs/maps.md'])
        piece_inventory = map_piece_regions.inventory(rom)
        add('map piece bank thresholds',0xD0000,3,2,[('bank threshold',0,2)],['tools/map_native.py','docs/maps.md'])
        for piece in piece_inventory['pieces']:
            add('map piece %d pointer'%piece['id'],0xD0004+2*piece['id'],1,2,[('piece offset',0,2)],
                ['tools/map_native.py','tools/map_piece_regions.py','docs/maps.md'])
            add('map piece %d encoded body'%piece['id'],piece['offset'],1,piece['encoded_size'],
                [('dimensions, subpatterns and body',0,piece['encoded_size'])],
                ['tools/map_native.py','tools/map_piece_regions.py','docs/maps.md'])
        for asset in map_asset_regions.inventory(rom)['regions']:
            add(asset['name'],asset['offset'],1,asset['size'],[(asset['type'],0,asset['size'])],
                ['tools/map_asset_regions.py','tools/map_native.py','docs/maps.md'])
        tile_streams = map_tile_streams.inventory(rom)
        add('map tile-word stream pointers',0xB4000,33,3,[('encoded bank and offset',0,3)],tile_streams['evidence'])
        for stream in tile_streams['streams']:
            add('map tile-word stream %d'%stream['selector'],stream['offset'],1,stream['encoded_size'],
                [('bit-packed commands and unused tail bits',0,stream['encoded_size'])],tile_streams['evidence'])
        for script in script_regions.inventory(rom)['regions']:
            add(script['name'],script['offset'],1,script['size'],[(script['type'],0,script['size'])],
                ['tools/script_regions.py','tools/event_vm.py','tools/aidis.py','docs/cutscene-engine.md',
                 'docs/monster-ai-opcodes.md','docs/text.md'])
        for dispatch in dispatch_tables.inventory(rom)['tables']:
            add(dispatch['name'],dispatch['offset'],dispatch['count'],2,[('handler offset',0,2)],dispatch['evidence'])
        # Only the bytes whose meaning is documented are counted, not the unknown record fields.
        for source,dest in ((0xC77C00,0x7E8000),(0xC7B480,0x7E5000),(0xDCF240,0x7E2000),
                            (0xDCE800,0x7E4000),(0xC7C1C0,0x7E4C00)):
            image,info = boot_decode.decode(rom,source,dest)
            actual = boot_decode.execute(rom,source,dest)
            lo = dest&0xFFFF
            assert image[lo:lo+info['output_size']] == actual.wram[lo:lo+info['output_size']]
            add('compressed block %06X'%source,source&0x3FFFFF,1,info['encoded_size'],
                [('encoded block',0,info['encoded_size'])],['docs/boot.md','tools/boot_decode.py'],'verified')
        audio = boot_audio.validate(rom)
        add('sound boot source pointers',0x30008,6,2,[('bank C3 offset',0,2)],['docs/audio.md','tools/boot_audio.py'])
        add('sound boot destination pointers',0x30014,6,2,[('SPC RAM offset',0,2)],['docs/audio.md','tools/boot_audio.py'])
        for block in audio['blocks']:
            start = int(block['source'],16)&0x3FFFFF
            add('SPC upload block '+block['source'],start,1,block['encoded_size'],
                [('length and upload payload',0,block['encoded_size'])],['docs/audio.md','tools/boot_audio.py'],'verified')
        colour = boot_coefficients.verify_real_image(rom)
        add('colour binary tree D2E536',int(colour['tree_source'],16)&0x3FFFFF,1,colour['tree_size'],
            [('serialized relative branches and leaves',0,colour['tree_size'])],
            ['tools/boot_colour.py','docs/boot.md','data/boot_colour.json'],'verified')
        for segment in colour['stream_segments']:
            add('colour coefficient stream verified prefix '+segment['source'],int(segment['source'],16)&0x3FFFFF,1,segment['size'],
                [('palette and 1152 coefficient blocks consumed prefix',0,segment['size'])],
                ['tools/boot_coefficients.py','docs/boot.md','data/boot_coefficients.json'],'verified')
    source_path = os.path.join(ROOT,'data/source_build.json')
    source_report = json.load(open(source_path))
    assert source_report['verified'] and source_report['rom_sha256']==hashlib.sha256(rom).hexdigest()
    manifest_path = os.path.join(ROOT,'src/manifest.json')
    assert source_report['manifest_sha256']==hashlib.sha256(open(manifest_path,'rb').read()).hexdigest()
    for block in source_report['blocks']:
        source = os.path.join(ROOT,block['source'])
        assert block['source_sha256']==hashlib.sha256(open(source,'rb').read()).hexdigest()
        if block['reference']!='rom': continue
        start = int(block['address'],16)&0x3FFFFF
        assert block['assembled_sha256']==hashlib.sha256(rom[start:start+block['size']]).hexdigest()
        add('matching source '+block['address'],start,1,block['size'],
            [('assembled '+block.get('kind','code'),0,block['size'])],
            [block['source'],'data/source_build.json','tools/verify_source.py'],'matching_source')
    size = len(rom)
    report = {'rom_size':size,'rom_sha256':hashlib.sha256(rom).hexdigest(),
              'metric':'Union of audited documented ROM byte ranges; lower bound, not completed decompilation',
              'catalogued_bytes':sum(documented),'catalogued_percent':100*sum(documented)/size,
              'execution_verified_region_bytes':sum(verified),
              'execution_verified_region_percent':100*sum(verified)/size,
              'matching_source_bytes':source_report['matching_source_bytes'],
              'matching_ram_source_bytes':source_report['matching_ram_source_bytes'],
              'matching_rom_source_bytes':source_report['matching_rom_source_bytes'],
              'matching_data_source_bytes':source_report['matching_data_source_bytes'],
              'matching_instruction_source_bytes':source_report['matching_instruction_source_bytes'],
              'matching_65816_instruction_source_bytes':source_report['matching_65816_instruction_source_bytes'],
              'matching_spc_instruction_source_bytes':source_report['matching_spc_instruction_source_bytes'],
              'full_code_decompilation_percent':None,
              'reason':'Total code extent and complete catalog of prior models are not established',
              'regions':len(regions),'existing_work_audit_complete':False}
    return regions,report

def main():
    rom = romio.rom_from_argv()
    reuse = '--reuse-audited-regions' in sys.argv
    assert not (reuse and '--refresh-audit-cache' in sys.argv)
    regions,report = build(rom, reuse)
    if '--refresh-audit-cache' in sys.argv:
        from rom_progress_cache import refresh
        refresh(rom, regions)
    print(json.dumps(report,indent=2))
    if '--write' in sys.argv:
        for filename,data in (('rom_regions.json',{'rom_sha256':report['rom_sha256'],'regions':regions}),
                              ('progress.json',report)):
            with open(os.path.join(ROOT,'data',filename),'w') as f:
                json.dump(data,f,indent=2)
                f.write('\n')

if __name__ == '__main__':
    main()
