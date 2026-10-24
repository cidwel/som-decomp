; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $06BF
actor_collision_byte_d306bf:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d306c0:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
