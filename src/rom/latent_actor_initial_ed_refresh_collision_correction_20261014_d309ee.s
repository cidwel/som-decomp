; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $09EE
actor_collision_byte_d309ee:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d309ef:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
