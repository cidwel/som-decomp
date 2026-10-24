; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $46B6
actor_collision_byte_d346b6:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d346b7:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d346b8:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d346b9:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
