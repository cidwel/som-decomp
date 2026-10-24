; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $19A7
actor_collision_byte_d319a7:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d319a8:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
