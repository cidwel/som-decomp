"""Independent mnemonic assembly source for recovered SPC initialization bodies."""
import hashlib
import re

import spc700

BODIES = {
0x0200: '''
CLRP
DI
MOV X,#$FF
MOV SP,X
MOV A,#$00
MOV X,A
clear_dp:
MOV (X)+,A
CMP X,#$F0
BNE clear_dp
MOV A,#$00
MOV Y,#$0C
CALL !$061B
MOV Y,#$1C
CALL !$061B
MOV Y,#$2C
CALL !$061B
MOV Y,#$3C
CALL !$061B
MOV Y,#$2D
CALL !$061B
MOV Y,#$3D
CALL !$061B
MOV Y,#$4D
CALL !$061B
MOV Y,#$5D
MOV A,#$19
CALL !$061B
MOV Y,#$07
MOV X,#$A0
voice_gain:
MOV $F2,Y
MOV $F3,X
MOV A,Y
CLRC
ADC A,#$10
MOV Y,A
BPL voice_gain
MOV $F1,#$F0
MOV $FA,#$24
MOV $F1,#$01
MOV $DF,#$02
CALL !$12DE
CALL !$132F
MOV A,#$7F
MOV Y,#$0C
CALL !$061B
MOV Y,#$1C
CALL !$061B
MOV $B0,#$FF
MOV $DD,#$07
SET1 $90.7
SET1 $9C.7
MOV Y,#$08
MOV A,#$FF
clear_upper_flags:
MOV !$FF7F+Y,A
DBNZ Y,clear_upper_flags
''',
0x061B: '''
MOV $F2,Y
MOV $F3,A
RET
''',
0x12DE: '''
MOV $F2,#$6C
MOV A,$F3
OR A,#$20
MOV $F3,A
MOV A,#$00
MOV Y,#$4D
CALL !$061B
MOV Y,#$0D
CALL !$061B
MOV Y,#$2C
CALL !$061B
MOV Y,#$3C
CALL !$061B
MOV Y,#$7D
MOV $F2,Y
MOV A,$F3
AND A,#$0F
MOV $E0,A
MOV A,$DF
CALL !$061B
MOV Y,A
BNE delay_nonzero
INC A
delay_nonzero:
ASL A
ASL A
ASL A
EOR A,#$FF
INC A
CLRC
ADC A,#$FA
MOV Y,#$6D
CALL !$061B
MOV $E2,A
MOV $E1,#$00
MOV $F1,#$01
MOV $FB,#$80
MOV $F1,#$03
MOV A,$FE
RET
''',
0x132F: '''
MOV A,#$00
MOV Y,A
clear_echo_page:
MOV [$E1]+Y,A
INC Y
BNE clear_echo_page
INC $E2
CMP $E2,#$FA
BNE clear_echo_page
MOV A,$FE
BRA check_previous_delay
wait_previous_delay:
MOV Y,$FE
BEQ wait_previous_delay
INC A
check_previous_delay:
CMP A,$E0
BCC wait_previous_delay
MOV $F2,#$6C
MOV A,$F3
AND A,#$DF
MOV $F3,A
MOV A,$FE
BRA check_current_delay
wait_current_delay:
MOV Y,$FE
BEQ wait_current_delay
INC A
check_current_delay:
CMP A,$DF
BCC wait_current_delay
MOV A,$A7
MOV Y,#$2C
CALL !$061B
MOV Y,#$3C
CALL !$061B
AND $C7,#$03
MOV A,$C7
ASL A
ASL A
ASL A
MOV Y,A
MOV X,#$0F
filter_registers:
MOV A,!$150C+Y
MOV $F2,X
MOV $F3,A
INC Y
MOV A,X
CLRC
ADC A,#$10
MOV X,A
BPL filter_registers
MOV Y,#$0D
MOV A,$C8
JMP !$061B
'''}


def instruction(line):
    for opcode,(template,kinds) in enumerate(spc700.OPS):
        pattern = re.escape(template)
        for position in range(len(kinds)):
            pattern = pattern.replace(re.escape('{'+str(position)+'}'),rf'(?P<p{position}>\$[0-9A-Fa-f]{{2,4}}|[a-z_][a-z_0-9]*)')
        matched = re.fullmatch(pattern,line)
        if matched:return opcode,kinds,matched.groupdict()
    raise ValueError(('SPC mnemonic not supported',line))


def assemble(entry,text):
    parsed = [];labels = {};pc = entry
    for raw in text.splitlines():
        line = raw.strip()
        if not line:continue
        if line.endswith(':'):labels[line[:-1]] = pc;continue
        opcode,kinds,args = instruction(line);parsed.append((pc,opcode,kinds,args));pc += spc700.length(opcode)
    result = bytearray()
    for pc,opcode,kinds,args in parsed:
        result.append(opcode)
        for position,kind in enumerate(kinds):
            token = args[f'p{position}'];value = labels[token] if token in labels else int(token.removeprefix('$'),16)
            if kind=='r':
                value -= pc+spc700.length(opcode)
                assert -128<=value<=127,(hex(pc),token,value)
                value &= 255
            size = spc700.KSZ[kind]
            assert 0<=value<1<<(size*8),(hex(pc),kind,token,value)
            result.extend(value.to_bytes(size,'little'))
    return bytes(result)


def verify(rom,mapping):
    records = []
    for function in mapping:
        entry = int(function['spc_entry'],16);address = int(function['rom_entry'],16);assembled = assemble(entry,BODIES[entry])
        assert len(assembled)==function['size'],(hex(entry),len(assembled),function['size'])
        assert assembled==rom[address&0x3FFFFF:(address&0x3FFFFF)+len(assembled)],('SPC assembly mismatch',hex(entry))
        records.append(dict(spc_entry=function['spc_entry'],rom_entry=function['rom_entry'],size=len(assembled),sha256=hashlib.sha256(assembled).hexdigest()))
    return records
