; SPC $08F3; physical ROM $C30E3D; native instrument control.
MOV A,$5D+X
ASL A
MOV Y,A
MOV A,!$1880+Y
MOV !$FE80+X,A
MOV A,!$1881+Y
MOV !$FE81+X,A
BRA $08A0
