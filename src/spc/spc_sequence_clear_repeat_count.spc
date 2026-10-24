; SPC $093A; physical ROM $C30E84; native sequence command.
CMP X,#$10
BCS $0943
MOV A,#$00
MOV !$FEA0+X,A
RET
