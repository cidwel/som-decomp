; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2E68
actor_collision_byte_d32e68:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32e69:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
