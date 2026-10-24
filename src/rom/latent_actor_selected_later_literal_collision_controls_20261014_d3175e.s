; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $175E
actor_collision_byte_d3175e:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d3175f:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $24
