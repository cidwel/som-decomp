; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $309D
actor_collision_byte_d3309d:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d3309e:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $55
