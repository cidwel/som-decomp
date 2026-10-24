; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $200B
actor_collision_byte_d2200b:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $18
actor_collision_byte_d2200c:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
