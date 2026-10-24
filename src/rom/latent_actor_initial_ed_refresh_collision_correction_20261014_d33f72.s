; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3F72
actor_collision_byte_d33f72:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d33f73:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $36
