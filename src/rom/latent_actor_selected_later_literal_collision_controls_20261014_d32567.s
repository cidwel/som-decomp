; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2567
actor_collision_byte_d32567:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32568:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $87
actor_collision_byte_d32569:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d3256a:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $75
