; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1E7F
actor_collision_byte_d21e7f:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d21e80:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
