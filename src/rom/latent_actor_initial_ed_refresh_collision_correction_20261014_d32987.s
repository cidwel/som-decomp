; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2987
actor_collision_byte_d32987:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $01
actor_collision_byte_d32988:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $45
actor_collision_byte_d32989:
    ; signed-XY-nibbles into actorCC collision box
    .byte $0D
actor_collision_byte_d3298a:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
