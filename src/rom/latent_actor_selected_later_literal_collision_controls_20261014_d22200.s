; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2200
actor_collision_byte_d22200:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d22201:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
