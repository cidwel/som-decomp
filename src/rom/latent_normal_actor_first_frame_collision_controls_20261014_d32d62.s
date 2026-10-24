; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2D62
actor_collision_byte_d32d62:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $20
actor_collision_byte_d32d63:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
