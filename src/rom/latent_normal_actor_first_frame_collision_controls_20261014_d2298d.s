; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $298D
actor_collision_byte_d2298d:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d2298e:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
