; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0D10
actor_collision_byte_d20d10:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d20d11:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
