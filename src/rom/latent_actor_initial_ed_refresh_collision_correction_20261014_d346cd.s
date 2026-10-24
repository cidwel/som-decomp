; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $46CD
actor_collision_byte_d346cd:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d346ce:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d346cf:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d346d0:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
