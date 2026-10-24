; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1AFE
actor_collision_byte_d31afe:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d31aff:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $55
