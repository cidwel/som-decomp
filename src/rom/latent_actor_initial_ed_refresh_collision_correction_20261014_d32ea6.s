; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2EA6
actor_collision_byte_d32ea6:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32ea7:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
