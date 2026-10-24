; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $469F
actor_collision_byte_d3469f:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d346a0:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d346a1:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d346a2:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
