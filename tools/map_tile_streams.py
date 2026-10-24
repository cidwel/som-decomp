"""Structural inventory of the 33 original packed tile-word streams.
Only pointers, lengths, command counts and hashes are saved; tile payloads stay in memory.
"""
import hashlib
import json
import sys
from pathlib import Path

import map_tile_words
import romio
from actor_program_calls import word


def inventory(rom):
    records = []
    mask = bytearray(len(rom))
    for selector in range(33):
        memory = bytearray(0x20000)
        decoded = map_tile_words.decode(rom,memory,selector|128)
        extended = decoded['extended']
        bits = decoded['words']*2+sum(extended)*2+(extended[0]+extended[1])*6+extended[2]*10+extended[3]*16
        start = int.from_bytes(rom[0xB4000+selector*3:0xB4003+selector*3],'little')|0xC00000
        cursor = memory[0x12]<<16|word(memory,0x10)
        assert decoded['words']==1536 and cursor==start+bits//8
        assert decoded['pairs']==4-(bits%8)//2
        length = (bits+7)//8
        offset = start&0x1FFFFF
        assert offset+length<=len(rom)
        mask[offset:offset+length] = bytes((1,))*length
        records.append(dict(selector=selector,address=f'{start:06X}',offset=offset,encoded_size=length,consumed_bits=bits,
                            unused_tail_bits=(-bits)%8,words=decoded['words'],layer_words=768,
                            commands=decoded['commands'],extended_commands=extended,
                            source_sha256=hashlib.sha256(rom[offset:offset+length]).hexdigest(),
                            first_layer_sha256=hashlib.sha256(memory[0x1C000:0x1C600]).hexdigest(),
                            second_layer_sha256=hashlib.sha256(memory[0x1C800:0x1CE00]).hexdigest()))
    for index in tuple(range(29))+(30,31):
        assert records[index]['offset']+records[index]['encoded_size']==records[index+1]['offset']
    return dict(rom_sha256=hashlib.sha256(rom).hexdigest(),streams=records,unique_encoded_bytes=sum(mask),pointer_table_bytes=99,
                evidence=['tools/map_tile_words.py','data/map_tile_words.json','tools/map_tile_bitreaders.py','data/map_tile_bitreaders.json','docs/maps.md'],
                scope='All33 original streams decode1536 words into two768-word layers. Exact bit consumption and native reader pointer/pair endpoint agree; adjacent streams meet at every table boundary within each allocation. Full bytes include documented unconstrained unused low bits of the final partial byte. Native initializer proofs exercise every selector in all four layer modes and all394 actual map headers. Structural hashes/counts only; no original or decoded tile payloads saved. Selector33..63,allocation gaps,padding between pointer table and first stream,and whole-ROM reconstruction remain open.')


if __name__=='__main__':
    report = inventory(romio.load(sys.argv[1]))
    if '--json' in sys.argv:Path(sys.argv[sys.argv.index('--json')+1]).write_text(json.dumps(report,indent=2)+'\n')
    print(f"{len(report['streams'])} tile-word streams,{report['unique_encoded_bytes']} unique encoded bytes")
