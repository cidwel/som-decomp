; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $37F4
actor_collision_byte_d237f4:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d237f5:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $32
