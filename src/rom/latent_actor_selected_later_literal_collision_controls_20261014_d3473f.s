; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $473F
actor_collision_byte_d3473f:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34740:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d34741:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d34742:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
