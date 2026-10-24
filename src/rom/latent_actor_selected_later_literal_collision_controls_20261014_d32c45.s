; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2C45
actor_collision_byte_d32c45:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32c46:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
