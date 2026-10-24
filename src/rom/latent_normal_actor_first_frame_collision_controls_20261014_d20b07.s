; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B07
actor_collision_byte_d20b07:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d20b08:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $63
