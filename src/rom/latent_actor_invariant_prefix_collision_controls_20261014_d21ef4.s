; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1EF4
actor_collision_byte_d21ef4:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d21ef5:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
