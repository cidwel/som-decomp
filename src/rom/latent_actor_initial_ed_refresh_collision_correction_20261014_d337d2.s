; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $37D2
actor_collision_byte_d337d2:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d337d3:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $65
