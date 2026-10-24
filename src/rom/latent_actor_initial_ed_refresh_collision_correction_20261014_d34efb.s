; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4EFB
actor_collision_byte_d34efb:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34efc:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $65
