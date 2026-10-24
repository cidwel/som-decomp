; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3F8D
actor_collision_byte_d23f8d:
    ; signed-XY-nibbles into actorCC collision box
    .byte $81
actor_collision_byte_d23f8e:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $32
