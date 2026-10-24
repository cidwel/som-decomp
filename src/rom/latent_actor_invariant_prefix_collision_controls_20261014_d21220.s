; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1220
actor_collision_byte_d21220:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d21221:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
