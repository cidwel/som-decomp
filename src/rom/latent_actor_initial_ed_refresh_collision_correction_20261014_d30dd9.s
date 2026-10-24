; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0DD9
actor_collision_byte_d30dd9:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d30dda:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
