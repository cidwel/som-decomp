; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $49F6
actor_collision_byte_d349f6:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d349f7:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
