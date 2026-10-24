; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $08DE
actor_collision_byte_d308de:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d308df:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
