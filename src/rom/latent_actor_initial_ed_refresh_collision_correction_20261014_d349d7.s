; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $49D7
actor_collision_byte_d349d7:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d349d8:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
