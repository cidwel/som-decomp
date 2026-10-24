; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0DAF
actor_collision_byte_d20daf:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $11
actor_collision_byte_d20db0:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
