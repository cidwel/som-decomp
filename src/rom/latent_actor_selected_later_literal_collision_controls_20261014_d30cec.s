; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0CEC
actor_collision_byte_d30cec:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30ced:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
