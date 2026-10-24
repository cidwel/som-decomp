; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3A6C
actor_collision_byte_d33a6c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33a6d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
