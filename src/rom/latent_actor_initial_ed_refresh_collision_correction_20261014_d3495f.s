; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $495F
actor_collision_byte_d3495f:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34960:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
