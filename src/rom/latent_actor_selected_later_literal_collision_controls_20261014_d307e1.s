; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $07E1
actor_collision_byte_d307e1:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d307e2:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
