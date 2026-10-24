; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0E83
actor_collision_byte_d30e83:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d30e84:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $46
