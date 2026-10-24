; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1744
actor_collision_byte_d31744:
    ; signed-XY-nibbles into actorCC collision box
    .byte $F0
actor_collision_byte_d31745:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
