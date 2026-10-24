; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4E93
actor_collision_byte_d34e93:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34e94:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $65
