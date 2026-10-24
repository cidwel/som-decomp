; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $48CC
actor_collision_byte_d248cc:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $20
actor_collision_byte_d248cd:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $22
