; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2CDE
actor_collision_byte_d32cde:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32cdf:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $58
