; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $31F1
actor_collision_byte_d331f1:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d331f2:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
