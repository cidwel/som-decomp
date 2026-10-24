; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3A12
actor_collision_byte_d23a12:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d23a13:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $32
