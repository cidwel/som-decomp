; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $34C5
actor_collision_byte_d234c5:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d234c6:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
