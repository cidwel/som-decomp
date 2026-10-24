; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4726
actor_collision_byte_d34726:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34727:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d34728:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d34729:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
