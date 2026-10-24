; SPC $0CAF; physical ROM $C311F9; public complete command receiver.
MOV X,$F4
BEQ finished
MOVW YA,$F6
MOVW $B6,YA
MOVW YA,$F4
MOVW $B4,YA
CMP A,#$83
BNE acknowledge
MOV $F5,Y
acknowledge:
MOV $F4,A
wait_sender:
CMP A,$F4
BEQ wait_sender
MOV X,A
BPL positive
CMP X,#$FE
BNE high_command
JMP !$11EA
high_command:
MOV $F4,#$00
JMP !$0FF9
positive:
CMP X,#$01
BEQ music
MOV $F4,#$00
CMP X,#$02
BNE builtin_range
JMP !$0E10
builtin_range:
CMP X,#$10
BCC finished
CMP X,#$20
BCS finished
JMP !$0EF6
finished:
RET
music:
