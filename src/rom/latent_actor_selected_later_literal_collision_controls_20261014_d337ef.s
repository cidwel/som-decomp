; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $37EF
actor_collision_byte_d337ef:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d337f0:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $65
