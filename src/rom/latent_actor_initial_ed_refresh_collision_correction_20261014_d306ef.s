; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $06EF
actor_collision_byte_d306ef:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d306f0:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
