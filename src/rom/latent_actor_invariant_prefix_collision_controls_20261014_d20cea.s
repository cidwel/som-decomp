; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0CEA
actor_collision_byte_d20cea:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d20ceb:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
