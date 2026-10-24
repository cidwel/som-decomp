; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $37B7
actor_collision_byte_d337b7:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $52
actor_collision_byte_d337b8:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
