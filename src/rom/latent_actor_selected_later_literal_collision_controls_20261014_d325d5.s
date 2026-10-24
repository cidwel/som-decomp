; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $25D5
actor_collision_byte_d325d5:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d325d6:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $75
actor_collision_byte_d325d7:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d325d8:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $64
