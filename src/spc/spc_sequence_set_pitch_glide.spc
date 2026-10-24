; SPC $0720; physical ROM $C30C6A; native sequence command.
INC A
MOV !$FCC1+X,A
CALL !$0562
MOV !$0120+X,A
RET
