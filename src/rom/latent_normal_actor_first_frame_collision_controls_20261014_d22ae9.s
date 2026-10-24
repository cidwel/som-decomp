; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2AE9
actor_collision_byte_d22ae9:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d22aea:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
