; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2C6D
actor_collision_byte_d32c6d:
    ; signed-XY-nibbles into actorCC collision box
    .byte $F0
actor_collision_byte_d32c6e:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $66
