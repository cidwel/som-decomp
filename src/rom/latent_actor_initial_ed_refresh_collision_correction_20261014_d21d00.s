; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1D00
actor_collision_byte_d21d00:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d21d01:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
