; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $29CC
actor_collision_byte_d229cc:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d229cd:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
