; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1D19
actor_collision_byte_d21d19:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d21d1a:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
