; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1F45
actor_collision_byte_d31f45:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d31f46:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
