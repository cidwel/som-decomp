; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1ACD
actor_collision_byte_d31acd:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d31ace:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $55
