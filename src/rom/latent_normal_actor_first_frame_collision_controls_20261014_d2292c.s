; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $292C
actor_collision_byte_d2292c:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d2292d:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
