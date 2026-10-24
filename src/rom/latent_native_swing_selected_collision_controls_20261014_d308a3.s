; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $08A3
actor_collision_byte_d308a3:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d308a4:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d308a5:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d308a6:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
