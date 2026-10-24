; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AA4
actor_collision_byte_d20aa4:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d20aa5:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $63
