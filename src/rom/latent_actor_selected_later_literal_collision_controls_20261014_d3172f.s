; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $172F
actor_collision_byte_d3172f:
    ; signed-XY-nibbles into actorCC collision box
    .byte $D0
actor_collision_byte_d31730:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
