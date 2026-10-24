; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $31D2
actor_collision_byte_d331d2:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d331d3:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
