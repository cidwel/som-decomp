; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3E7C
actor_collision_byte_d33e7c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $01
actor_collision_byte_d33e7d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
