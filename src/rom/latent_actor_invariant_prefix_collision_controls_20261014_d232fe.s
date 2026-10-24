; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $32FE
actor_collision_byte_d232fe:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d232ff:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
