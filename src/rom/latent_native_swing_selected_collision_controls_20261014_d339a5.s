; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $39A5
actor_collision_byte_d339a5:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d339a6:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $74
actor_collision_byte_d339a7:
    ; signed-XY-nibbles into actorCC collision box
    .byte $E0
actor_collision_byte_d339a8:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $54
