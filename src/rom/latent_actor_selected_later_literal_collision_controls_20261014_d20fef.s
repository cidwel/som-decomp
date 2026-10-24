; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0FEF
actor_collision_byte_d20fef:
    ; signed-XY-nibbles into actorCC collision box
    .byte $18
actor_collision_byte_d20ff0:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
