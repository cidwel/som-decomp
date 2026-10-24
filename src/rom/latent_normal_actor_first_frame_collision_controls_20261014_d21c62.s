; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1C62
actor_collision_byte_d21c62:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d21c63:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $63
