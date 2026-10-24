; SPC $0620; physical ROM $C30B6A; native sequence command.
CMP X,#$10
BCS $062C
MOV $7D,A
MOV A,#$00
MOV $7C,A
MOV $80,A
RET
