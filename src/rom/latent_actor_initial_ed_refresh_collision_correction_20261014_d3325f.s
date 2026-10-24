; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $325F
actor_collision_byte_d3325f:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d33260:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
