; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1F14
actor_collision_byte_d21f14:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d21f15:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
