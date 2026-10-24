; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2BC3
actor_collision_byte_d32bc3:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32bc4:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $54
actor_collision_byte_d32bc5:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d32bc6:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $54
