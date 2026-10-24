; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2457
actor_collision_byte_d22457:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d22458:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
