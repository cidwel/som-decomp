; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2499
actor_collision_byte_d22499:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d2249a:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
