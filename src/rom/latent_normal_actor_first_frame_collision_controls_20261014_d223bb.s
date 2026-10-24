; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $23BB
actor_collision_byte_d223bb:
    ; signed-XY-nibbles into actorCC collision box
    .byte $F0
actor_collision_byte_d223bc:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
