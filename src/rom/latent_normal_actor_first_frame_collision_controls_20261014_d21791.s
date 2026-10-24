; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1791
actor_collision_byte_d21791:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d21792:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
