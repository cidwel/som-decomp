; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2232
actor_collision_byte_d32232:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32233:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $56
