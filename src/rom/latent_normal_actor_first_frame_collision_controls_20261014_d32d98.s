; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2D98
actor_collision_byte_d32d98:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d32d99:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
