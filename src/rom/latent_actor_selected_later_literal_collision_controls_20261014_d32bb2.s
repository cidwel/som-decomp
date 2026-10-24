; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2BB2
actor_collision_byte_d32bb2:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32bb3:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
