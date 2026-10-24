; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1FE0
actor_collision_byte_d31fe0:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d31fe1:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
