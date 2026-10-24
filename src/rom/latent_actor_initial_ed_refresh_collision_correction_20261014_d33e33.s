; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3E33
actor_collision_byte_d33e33:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d33e34:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
