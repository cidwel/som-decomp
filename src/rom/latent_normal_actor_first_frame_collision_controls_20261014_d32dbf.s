; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2DBF
actor_collision_byte_d32dbf:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d32dc0:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
