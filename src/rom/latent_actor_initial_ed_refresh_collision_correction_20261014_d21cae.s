; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1CAE
actor_collision_byte_d21cae:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d21caf:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $63
