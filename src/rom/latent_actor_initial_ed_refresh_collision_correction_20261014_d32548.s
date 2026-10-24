; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2548
actor_collision_byte_d32548:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d32549:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $87
actor_collision_byte_d3254a:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d3254b:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $75
