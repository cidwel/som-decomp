; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3980
actor_collision_byte_d33980:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d33981:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $48
actor_collision_byte_d33982:
    ; signed-XY-nibbles into actorCC collision box
    .byte $F1
actor_collision_byte_d33983:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $47
