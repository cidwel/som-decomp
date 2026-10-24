; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2E05
actor_collision_byte_d32e05:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d32e06:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
