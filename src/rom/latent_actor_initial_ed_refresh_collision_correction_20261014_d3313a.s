; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $313A
actor_collision_byte_d3313a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3313b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
