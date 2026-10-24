; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1C67
actor_collision_byte_d31c67:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d31c68:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
