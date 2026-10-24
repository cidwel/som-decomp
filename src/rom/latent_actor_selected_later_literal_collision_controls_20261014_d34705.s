; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4705
actor_collision_byte_d34705:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34706:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d34707:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d34708:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
