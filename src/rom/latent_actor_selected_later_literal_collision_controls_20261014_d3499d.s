; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $499D
actor_collision_byte_d3499d:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d3499e:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
