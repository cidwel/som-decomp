; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0DF9
actor_collision_byte_d20df9:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $18
actor_collision_byte_d20dfa:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
