; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4DB4
actor_collision_byte_d34db4:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d34db5:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
