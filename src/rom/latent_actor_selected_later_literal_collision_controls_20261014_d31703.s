; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1703
actor_collision_byte_d31703:
    ; signed-XY-nibbles into actorCC collision box
    .byte $D0
actor_collision_byte_d31704:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
