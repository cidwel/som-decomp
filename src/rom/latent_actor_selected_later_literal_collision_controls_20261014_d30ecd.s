; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0ECD
actor_collision_byte_d30ecd:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d30ece:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
