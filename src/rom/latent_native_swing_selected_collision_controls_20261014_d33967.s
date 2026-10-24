; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3967
actor_collision_byte_d33967:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33968:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
actor_collision_byte_d33969:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d3396a:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $64
