; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $32AD
actor_collision_byte_d232ad:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $11
actor_collision_byte_d232ae:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $54
