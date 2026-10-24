; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3127
actor_collision_byte_d33127:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d33128:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
