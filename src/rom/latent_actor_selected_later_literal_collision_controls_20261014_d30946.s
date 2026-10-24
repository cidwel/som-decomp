; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0946
actor_collision_byte_d30946:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30947:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d30948:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d30949:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
