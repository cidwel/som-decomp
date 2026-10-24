; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $225D
actor_collision_byte_d2225d:
    ; signed-XY-nibbles into actorCC collision box
    .byte $18
actor_collision_byte_d2225e:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
