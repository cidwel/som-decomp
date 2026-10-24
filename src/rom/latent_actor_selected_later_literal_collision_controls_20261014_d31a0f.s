; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1A0F
actor_collision_byte_d31a0f:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d31a10:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
