; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $48A7
actor_collision_byte_d348a7:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d348a8:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $74
actor_collision_byte_d348a9:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d348aa:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $62
