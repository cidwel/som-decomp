; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3A31
actor_collision_byte_d23a31:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d23a32:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
