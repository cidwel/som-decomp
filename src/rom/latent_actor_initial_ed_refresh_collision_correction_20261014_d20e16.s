; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0E16
actor_collision_byte_d20e16:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $08
actor_collision_byte_d20e17:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
