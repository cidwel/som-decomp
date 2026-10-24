; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0C33
actor_collision_byte_d20c33:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d20c34:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
