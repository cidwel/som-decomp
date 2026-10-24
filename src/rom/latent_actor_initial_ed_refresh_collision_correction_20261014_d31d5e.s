; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1D5E
actor_collision_byte_d31d5e:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d31d5f:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
