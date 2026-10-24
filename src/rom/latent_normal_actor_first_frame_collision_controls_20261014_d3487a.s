; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $487A
actor_collision_byte_d3487a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3487b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $74
actor_collision_byte_d3487c:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d3487d:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $62
