; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BC9
actor_collision_byte_d30bc9:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30bca:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
