; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $091F
actor_collision_byte_d3091f:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30920:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
