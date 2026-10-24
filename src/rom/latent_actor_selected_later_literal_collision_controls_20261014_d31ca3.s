; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1CA3
actor_collision_byte_d31ca3:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d31ca4:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
