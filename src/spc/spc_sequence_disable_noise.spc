; SPC $07E5; physical ROM $C30D2F; native sequence command.
MOV A,$B2
CMP X,#$10
BCS $07F0
TCLR1 !$00BC
BRA $07DA
TCLR1 !$00BD
BRA $07DA
