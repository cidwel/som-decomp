; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2EE4
actor_collision_byte_d32ee4:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32ee5:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
