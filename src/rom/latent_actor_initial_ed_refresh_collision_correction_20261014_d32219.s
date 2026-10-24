; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2219
actor_collision_byte_d32219:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3221a:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $54
