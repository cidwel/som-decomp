; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1DAB
actor_collision_byte_d31dab:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d31dac:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
