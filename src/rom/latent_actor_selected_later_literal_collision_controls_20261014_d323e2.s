; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $23E2
actor_collision_byte_d323e2:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E0
actor_collision_byte_d323e3:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
actor_collision_byte_d323e4:
    ; signed-XY-nibbles into actorCC collision box
    .byte $20
actor_collision_byte_d323e5:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $24
