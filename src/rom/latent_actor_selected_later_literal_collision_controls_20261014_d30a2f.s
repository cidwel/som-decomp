; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A2F
actor_collision_byte_d30a2f:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d30a30:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
