; SPC $08E3; physical ROM $C30E2D; native instrument control.
AND A,#$1F
MOV $04,A
MOV A,!$FE81+X
AND A,#$E0
OR A,$04
MOV !$FE81+X,A
BRA $08A0
