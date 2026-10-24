; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3E95
actor_collision_byte_d33e95:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $01
actor_collision_byte_d33e96:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
