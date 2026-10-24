; SPC $0E10; physical ROM $C3135A; native effect allocation.
MOV $2C,$B5
MOV $2D,#$00
ASL $2C
ROL $2D
ASL $2C
ROL $2D
MOV A,#$00
MOV Y,#$2C
ADDW YA,$2C
MOVW $2C,YA
MOV X,#$00
MOV Y,#$01
MOV A,[$2C]+Y
BNE first_present
MOV Y,#$03
MOV A,[$2C]+Y
BEQ absent
DEC Y
BRA single_pointer
first_present:
MOV Y,#$03
MOV A,[$2C]+Y
BNE stereo
MOV Y,#$00
single_pointer:
MOV A,[$2C]+Y
MOV $30,A
INC Y
MOV A,[$2C]+Y
MOV $31,A
JMP !$0F11
absent:
RET
stereo:
MOV $B2,#$40
MOV X,#$1C
CALL !$0FCE
MOV A,Y
BEQ find_pair
CMP X,#$10
BEQ pair_ready
LSR $B2
DEC X
DEC X
BRA pair_ready
find_pair:
CMP $AE,#$FE
BCC search_pair
RET
search_pair:
MOV $B2,#$40
MOV X,#$1C
check_pair:
MOV A,$B2
AND A,$AE
BNE next_pair
MOV A,$B2
ASL A
AND A,$AE
BEQ pair_ready
next_pair:
DEC X
DEC X
LSR $B2
BNE check_pair
RET
pair_ready:
MOV A,$B2
ASL $B2
OR A,$B2
TSET1 !$00B0
TCLR1 !$00AF
TCLR1 !$00C9
TCLR1 !$00CA
TCLR1 !$00B8
TCLR1 !$00BA
TCLR1 !$00B9
TCLR1 !$00BD
TCLR1 !$00C1
TCLR1 !$00BF
TCLR1 !$00C3
TSET1 !$00AE
INC X
INC X
MOV A,X
LSR A
AND A,#$07
MOV Y,A
MOV A,$B5
MOV !$FF80+Y,A
MOV !$FF7F+Y,A
PUSH X
CALL !$0F91
POP X
MOV Y,#$03
initialize_pair_voice:
MOV A,[$2C]+Y
MOV $0D+X,A
DEC Y
MOV A,[$2C]+Y
MOV $0C+X,A
CALL !$0DE5
INC $3C+X
MOV A,#$64
MOV !$FC01+X,A
MOV A,$B7
MOV !$FC41+X,A
MOV A,$B6
MOV !$FC81+X,A
MOV A,$B4
MOV !$FC60+X,A
MOV A,$B5
MOV !$FC61+X,A
PUSH Y
MOV A,#$04
CALL !$0866
POP Y
DEC X
DEC X
LSR $B2
DEC Y
BPL initialize_pair_voice
RET
