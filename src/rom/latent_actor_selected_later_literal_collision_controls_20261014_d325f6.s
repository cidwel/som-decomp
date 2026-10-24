; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $25F6
actor_collision_byte_d325f6:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d325f7:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $75
actor_collision_byte_d325f8:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d325f9:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $64
