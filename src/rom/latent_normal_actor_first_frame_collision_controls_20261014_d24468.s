; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4468
actor_collision_byte_d24468:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d24469:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $32
