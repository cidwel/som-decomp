; SPC $083F; physical ROM $C30D89; native sequence command.
CMP X,#$10
BCS $0848
OR $C0,$B2
BRA $084B
OR $C1,$B2
MOV A,$AE
EOR A,#$FF
AND A,$C0
OR A,$C1
MOV $BA,A
RET
