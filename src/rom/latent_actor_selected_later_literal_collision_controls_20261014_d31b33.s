; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1B33
actor_collision_byte_d31b33:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d31b34:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $55
