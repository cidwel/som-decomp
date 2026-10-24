; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $16A2
actor_collision_byte_d216a2:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d216a3:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
