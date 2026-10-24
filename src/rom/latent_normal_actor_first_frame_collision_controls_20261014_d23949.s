; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3949
actor_collision_byte_d23949:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d2394a:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
