; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0CB6
actor_collision_byte_d30cb6:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30cb7:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
