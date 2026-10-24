; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $403F
actor_collision_byte_d3403f:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34040:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d34041:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d34042:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
