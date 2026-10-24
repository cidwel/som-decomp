; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4436
actor_collision_byte_d24436:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d24437:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
