; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0912
actor_collision_byte_d30912:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30913:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
