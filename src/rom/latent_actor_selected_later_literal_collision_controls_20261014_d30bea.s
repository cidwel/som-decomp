; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BEA
actor_collision_byte_d30bea:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30beb:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
