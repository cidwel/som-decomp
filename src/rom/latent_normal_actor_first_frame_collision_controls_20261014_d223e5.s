; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $23E5
actor_collision_byte_d223e5:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d223e6:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
