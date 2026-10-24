; SPC $0737; physical ROM $C30C81; native sequence command.
MOV !$0160+X,A
CALL !$0562
INC A
MOV !$FCA0+X,A
MOV A,#$01
MOV !$FCE0+X,A
CALL !$0562
