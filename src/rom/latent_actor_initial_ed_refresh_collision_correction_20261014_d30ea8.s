; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0EA8
actor_collision_byte_d30ea8:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d30ea9:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
