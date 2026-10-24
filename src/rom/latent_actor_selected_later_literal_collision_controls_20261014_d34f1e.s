; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4F1E
actor_collision_byte_d34f1e:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34f1f:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $65
