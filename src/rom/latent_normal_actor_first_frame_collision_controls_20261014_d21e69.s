; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1E69
actor_collision_byte_d21e69:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d21e6a:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
