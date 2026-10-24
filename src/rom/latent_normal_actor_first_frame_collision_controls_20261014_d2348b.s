; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $348B
actor_collision_byte_d2348b:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d2348c:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
