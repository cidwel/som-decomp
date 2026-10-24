; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1F22
actor_collision_byte_d31f22:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d31f23:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
