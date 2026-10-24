; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1726
actor_collision_byte_d31726:
    ; signed-XY-nibbles into actorCC collision box
    .byte $D0
actor_collision_byte_d31727:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
