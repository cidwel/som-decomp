; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $46E8
actor_collision_byte_d346e8:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d346e9:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d346ea:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d346eb:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
