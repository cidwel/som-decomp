; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3042
actor_collision_byte_d23042:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d23043:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $54
