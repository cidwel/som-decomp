; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2C24
actor_collision_byte_d32c24:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d32c25:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
