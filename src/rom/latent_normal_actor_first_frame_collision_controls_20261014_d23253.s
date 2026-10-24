; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3253
actor_collision_byte_d23253:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d23254:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $54
