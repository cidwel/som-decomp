; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $119B
actor_collision_byte_d2119b:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d2119c:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
