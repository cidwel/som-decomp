; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $7A0A
actor_collision_byte_d27a0a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $20
actor_collision_byte_d27a0b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
