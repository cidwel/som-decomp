; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2478
actor_collision_byte_d22478:
    ; signed-XY-nibbles into actorCC collision box
    .byte $22
actor_collision_byte_d22479:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
