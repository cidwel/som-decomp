; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3DF9
actor_collision_byte_d23df9:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d23dfa:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
