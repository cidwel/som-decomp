; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $484D
actor_collision_byte_d3484d:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3484e:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $74
actor_collision_byte_d3484f:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d34850:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $62
