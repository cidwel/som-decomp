; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1239
actor_collision_byte_d21239:
    ; signed-XY-nibbles into actorCC collision box
    .byte $80
actor_collision_byte_d2123a:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
