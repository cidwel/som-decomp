; SPC $0856; physical ROM $C30DA0; native sequence command.
MOV A,$B2
CMP X,#$10
BCS $0861
TCLR1 !$00C0
BRA $084B
TCLR1 !$00C1
BRA $084B
