; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $15F7
actor_collision_byte_d315f7:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E0
actor_collision_byte_d315f8:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $54
actor_collision_byte_d315f9:
    ; signed-XY-nibbles into actorCC collision box
    .byte $30
actor_collision_byte_d315fa:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $34
