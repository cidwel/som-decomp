; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3FE2
actor_collision_byte_d23fe2:
    ; signed-XY-nibbles into actorCC collision box
    .byte $8F
actor_collision_byte_d23fe3:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $32
