; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $34E6
actor_collision_byte_d234e6:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $80
actor_collision_byte_d234e7:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
