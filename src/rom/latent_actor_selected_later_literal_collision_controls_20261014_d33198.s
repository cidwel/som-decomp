; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3198
actor_collision_byte_d33198:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33199:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
