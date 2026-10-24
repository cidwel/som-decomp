; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A20
actor_collision_byte_d30a20:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d30a21:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
