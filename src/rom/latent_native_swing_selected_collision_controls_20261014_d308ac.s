; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $08AC
actor_collision_byte_d308ac:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d308ad:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d308ae:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d308af:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
