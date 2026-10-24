; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $25BE
actor_collision_byte_d325be:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d325bf:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $75
actor_collision_byte_d325c0:
    ; signed-XY-nibbles into actorCC collision box
    .byte $F0
actor_collision_byte_d325c1:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $64
