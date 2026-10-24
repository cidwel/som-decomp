; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $174F
actor_collision_byte_d3174f:
    ; signed-XY-nibbles into actorCC collision box
    .byte $F1
actor_collision_byte_d31750:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
