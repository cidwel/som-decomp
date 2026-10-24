; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AC2
actor_collision_byte_d20ac2:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d20ac3:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $63
