; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $310C
actor_collision_byte_d3310c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d3310d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
