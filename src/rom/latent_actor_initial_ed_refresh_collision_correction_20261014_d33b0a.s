; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3B0A
actor_collision_byte_d33b0a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d33b0b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $46
