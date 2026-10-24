idle_packet:
MOV $F4,X
wait_token:
CMP X,$F4
BEQ wait_token
MOV X,$F4
BNE idle_packet
JMP !$11EA
