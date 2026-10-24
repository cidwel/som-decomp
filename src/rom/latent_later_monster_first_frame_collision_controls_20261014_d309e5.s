; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $09E5
actor_collision_byte_d309e5:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d309e6:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
