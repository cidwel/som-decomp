; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2A86
actor_collision_byte_d22a86:
    ; signed-XY-nibbles into actorCC collision box
    .byte $18
actor_collision_byte_d22a87:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
