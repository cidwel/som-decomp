; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4DEE
actor_collision_byte_d34dee:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E0
actor_collision_byte_d34def:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
