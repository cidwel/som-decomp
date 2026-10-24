; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $497E
actor_collision_byte_d3497e:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $62
actor_collision_byte_d3497f:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
