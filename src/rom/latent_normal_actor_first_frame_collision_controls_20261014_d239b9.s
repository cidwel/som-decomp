; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $39B9
actor_collision_byte_d239b9:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d239ba:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
