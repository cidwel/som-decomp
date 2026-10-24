; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0C60
actor_collision_byte_d30c60:
    ; signed-XY-nibbles into actorCC collision box
    .byte $0F
actor_collision_byte_d30c61:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $55
