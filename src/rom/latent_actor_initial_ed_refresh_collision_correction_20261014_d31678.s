; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1678
actor_collision_byte_d31678:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d31679:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $84
