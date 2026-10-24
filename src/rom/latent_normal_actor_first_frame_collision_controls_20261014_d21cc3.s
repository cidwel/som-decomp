; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1CC3
actor_collision_byte_d21cc3:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d21cc4:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $63
