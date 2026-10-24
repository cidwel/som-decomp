; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1A85
actor_collision_byte_d31a85:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d31a86:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
