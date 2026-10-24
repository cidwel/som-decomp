; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1978
actor_collision_byte_d31978:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d31979:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
