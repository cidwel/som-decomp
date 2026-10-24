; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $31B5
actor_collision_byte_d331b5:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d331b6:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
