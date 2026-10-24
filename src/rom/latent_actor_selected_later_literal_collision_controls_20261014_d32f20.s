; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2F20
actor_collision_byte_d32f20:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32f21:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
