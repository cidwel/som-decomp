; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $409E
actor_collision_byte_d2409e:
    ; signed-XY-nibbles into actorCC collision box
    .byte $28
actor_collision_byte_d2409f:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
