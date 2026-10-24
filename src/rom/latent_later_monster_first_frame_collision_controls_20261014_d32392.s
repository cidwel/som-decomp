; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2392
actor_collision_byte_d32392:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d32393:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
