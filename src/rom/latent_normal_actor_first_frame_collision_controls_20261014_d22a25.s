; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2A25
actor_collision_byte_d22a25:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d22a26:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
