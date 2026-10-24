; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $097A
actor_collision_byte_d3097a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3097b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
