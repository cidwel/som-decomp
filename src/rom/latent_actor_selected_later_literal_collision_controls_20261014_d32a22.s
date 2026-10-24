; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2A22
actor_collision_byte_d32a22:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32a23:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d32a24:
    ; signed-XY-nibbles into actorCC collision box
    .byte $30
actor_collision_byte_d32a25:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $23
