; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $346C
actor_collision_byte_d2346c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $81
actor_collision_byte_d2346d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
