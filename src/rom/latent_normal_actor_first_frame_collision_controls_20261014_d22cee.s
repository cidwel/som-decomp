; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2CEE
actor_collision_byte_d22cee:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d22cef:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
