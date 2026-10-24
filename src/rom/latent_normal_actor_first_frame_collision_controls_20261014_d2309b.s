; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $309B
actor_collision_byte_d2309b:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $4F
actor_collision_byte_d2309c:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $54
