; SPC $07CE; physical ROM $C30D18; native sequence command.
CMP X,#$10
BCS $07D7
OR $BC,$B2
BRA $07DA
OR $BD,$B2
MOV A,$AE
EOR A,#$FF
AND A,$BC
OR A,$BD
MOV $B8,A
RET
