; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0FA0
actor_collision_byte_d20fa0:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d20fa1:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
