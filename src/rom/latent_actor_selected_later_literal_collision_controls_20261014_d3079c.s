; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $079C
actor_collision_byte_d3079c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3079d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $46
actor_collision_byte_d3079e:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d3079f:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
