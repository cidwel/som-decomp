; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $241F
actor_collision_byte_d2241f:
    ; signed-XY-nibbles into actorCC collision box
    .byte $80
actor_collision_byte_d22420:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
