; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $116D
actor_collision_byte_d2116d:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d2116e:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
