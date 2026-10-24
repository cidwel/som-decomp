; SPC $074D; physical ROM $C30C97; native sequence command.
MOV !$0161+X,A
CALL !$0562
INC A
MOV !$FCA1+X,A
MOV A,#$01
MOV !$FCE1+X,A
CALL !$0562
