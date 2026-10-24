; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1D3C
actor_collision_byte_d21d3c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $81
actor_collision_byte_d21d3d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
