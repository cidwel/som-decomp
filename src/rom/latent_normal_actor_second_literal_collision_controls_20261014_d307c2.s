; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $07C2
actor_collision_byte_d307c2:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d307c3:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
