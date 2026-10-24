; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3242
actor_collision_byte_d33242:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d33243:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
