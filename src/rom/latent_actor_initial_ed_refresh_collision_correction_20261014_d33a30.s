; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3A30
actor_collision_byte_d33a30:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33a31:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
