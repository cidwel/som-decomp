; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $237D
actor_collision_byte_d3237d:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d3237e:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
