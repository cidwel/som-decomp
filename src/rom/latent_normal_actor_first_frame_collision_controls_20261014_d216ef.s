; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $16EF
actor_collision_byte_d216ef:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d216f0:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
