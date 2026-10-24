; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $11D7
actor_collision_byte_d211d7:
    ; signed-XY-nibbles into actorCC collision box
    .byte $88
actor_collision_byte_d211d8:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
