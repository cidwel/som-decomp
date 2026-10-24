; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AF8
actor_collision_byte_d30af8:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d30af9:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $44
