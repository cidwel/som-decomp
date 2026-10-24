; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4557
actor_collision_byte_d34557:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34558:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
