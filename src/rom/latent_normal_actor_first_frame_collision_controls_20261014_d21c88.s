; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1C88
actor_collision_byte_d21c88:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d21c89:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $63
