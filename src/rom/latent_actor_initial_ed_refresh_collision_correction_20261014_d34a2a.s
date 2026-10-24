; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4A2A
actor_collision_byte_d34a2a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $20
actor_collision_byte_d34a2b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $48
