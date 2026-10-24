; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2584
actor_collision_byte_d32584:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d32585:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $87
actor_collision_byte_d32586:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d32587:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $75
