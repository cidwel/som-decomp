; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $08F8
actor_collision_byte_d308f8:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d308f9:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
