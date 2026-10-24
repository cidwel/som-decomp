; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $79CD
actor_collision_byte_d279cd:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d279ce:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
