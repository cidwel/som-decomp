; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3A4F
actor_collision_byte_d33a4f:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33a50:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
