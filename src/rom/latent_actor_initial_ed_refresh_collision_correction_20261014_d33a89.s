; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3A89
actor_collision_byte_d33a89:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33a8a:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
