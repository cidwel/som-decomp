; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1A70
actor_collision_byte_d21a70:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d21a71:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
