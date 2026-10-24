; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $397F
actor_collision_byte_d2397f:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d23980:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
