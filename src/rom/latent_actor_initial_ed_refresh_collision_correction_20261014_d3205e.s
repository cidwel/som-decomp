; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $205E
actor_collision_byte_d3205e:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $20
actor_collision_byte_d3205f:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $46
