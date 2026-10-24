; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3225
actor_collision_byte_d33225:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d33226:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
