; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $168D
actor_collision_byte_d3168d:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d3168e:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
actor_collision_byte_d3168f:
    ; signed-XY-nibbles into actorCC collision box
    .byte $F0
actor_collision_byte_d31690:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
