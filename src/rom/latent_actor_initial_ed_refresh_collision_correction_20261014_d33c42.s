; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3C42
actor_collision_byte_d33c42:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33c43:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
