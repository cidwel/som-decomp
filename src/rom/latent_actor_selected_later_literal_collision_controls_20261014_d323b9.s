; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $23B9
actor_collision_byte_d323b9:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E0
actor_collision_byte_d323ba:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
actor_collision_byte_d323bb:
    ; signed-XY-nibbles into actorCC collision box
    .byte $20
actor_collision_byte_d323bc:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $38
