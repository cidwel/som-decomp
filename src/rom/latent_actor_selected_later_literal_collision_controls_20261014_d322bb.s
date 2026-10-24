; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $22BB
actor_collision_byte_d322bb:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d322bc:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
