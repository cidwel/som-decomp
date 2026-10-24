; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1ECE
actor_collision_byte_d21ece:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d21ecf:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
