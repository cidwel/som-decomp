; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2B88
actor_collision_byte_d32b88:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32b89:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $58
