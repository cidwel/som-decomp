; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3ADE
actor_collision_byte_d33ade:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33adf:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
