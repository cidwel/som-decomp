; SPC $09B4; physical ROM $C30EFE; native sequence command.
CMP X,#$10
BCS $09BB
MOV !$FF88,A
RET
