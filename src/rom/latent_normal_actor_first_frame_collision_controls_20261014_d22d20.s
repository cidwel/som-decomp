; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2D20
actor_collision_byte_d22d20:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d22d21:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
