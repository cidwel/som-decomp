; SPC $0668; physical ROM $C30BB2; native sequence command.
MOV !$FC01+X,A
MOV A,#$00
MOV !$FC00+X,A
MOV !$FC80+X,A
RET
