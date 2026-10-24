; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4B03
actor_collision_byte_d34b03:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $52
actor_collision_byte_d34b04:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
actor_collision_byte_d34b05:
    ; signed-XY-nibbles into actorCC collision box
    .byte $EF
actor_collision_byte_d34b06:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $66
