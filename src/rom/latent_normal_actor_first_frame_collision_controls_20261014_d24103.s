; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4103
actor_collision_byte_d24103:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d24104:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $32
