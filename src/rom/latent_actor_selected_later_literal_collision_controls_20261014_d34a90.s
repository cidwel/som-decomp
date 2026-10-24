; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4A90
actor_collision_byte_d34a90:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34a91:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
actor_collision_byte_d34a92:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d34a93:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $66
