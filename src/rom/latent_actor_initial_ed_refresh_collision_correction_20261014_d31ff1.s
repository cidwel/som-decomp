; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1FF1
actor_collision_byte_d31ff1:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d31ff2:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
