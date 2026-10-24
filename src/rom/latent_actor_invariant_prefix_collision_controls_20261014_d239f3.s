; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $39F3
actor_collision_byte_d239f3:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d239f4:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
