; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0CCE
actor_collision_byte_d20cce:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d20ccf:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
