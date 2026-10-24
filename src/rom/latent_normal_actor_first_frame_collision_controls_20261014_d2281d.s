; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $281D
actor_collision_byte_d2281d:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d2281e:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
