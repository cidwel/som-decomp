; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $094F
actor_collision_byte_d3094f:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d30950:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
