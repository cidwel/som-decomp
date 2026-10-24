; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2C86
actor_collision_byte_d32c86:
    ; signed-XY-nibbles into actorCC collision box
    .byte $F0
actor_collision_byte_d32c87:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $66
