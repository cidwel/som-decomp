; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $08B5
actor_collision_byte_d308b5:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d308b6:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d308b7:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d308b8:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
