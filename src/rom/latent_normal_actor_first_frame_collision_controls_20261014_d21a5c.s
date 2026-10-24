; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1A5C
actor_collision_byte_d21a5c:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d21a5d:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
