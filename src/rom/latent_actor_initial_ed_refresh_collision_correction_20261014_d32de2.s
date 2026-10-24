; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2DE2
actor_collision_byte_d32de2:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $20
actor_collision_byte_d32de3:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
