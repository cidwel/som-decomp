; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $344B
actor_collision_byte_d2344b:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $20
actor_collision_byte_d2344c:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
