; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1738
actor_collision_byte_d21738:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d21739:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
