; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $17EA
actor_collision_byte_d217ea:
    ; signed-XY-nibbles into actorCC collision box
    .byte $18
actor_collision_byte_d217eb:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
