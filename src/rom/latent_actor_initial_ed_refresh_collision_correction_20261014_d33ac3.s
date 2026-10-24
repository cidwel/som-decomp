; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3AC3
actor_collision_byte_d33ac3:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33ac4:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
