; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1A68
actor_collision_byte_d31a68:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d31a69:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
