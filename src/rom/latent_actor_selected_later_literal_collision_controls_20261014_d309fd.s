; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $09FD
actor_collision_byte_d309fd:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d309fe:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
