; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2D3C
actor_collision_byte_d22d3c:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d22d3d:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
