; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0DD5
actor_collision_byte_d20dd5:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $01
actor_collision_byte_d20dd6:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
