; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0781
actor_collision_byte_d30781:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30782:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $46
actor_collision_byte_d30783:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d30784:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
