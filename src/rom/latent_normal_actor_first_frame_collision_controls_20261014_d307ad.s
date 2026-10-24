; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $07AD
actor_collision_byte_d307ad:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d307ae:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
