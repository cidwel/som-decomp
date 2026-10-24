; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $16AB
actor_collision_byte_d316ab:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $52
actor_collision_byte_d316ac:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
actor_collision_byte_d316ad:
    ; signed-XY-nibbles into actorCC collision box
    .byte $01
actor_collision_byte_d316ae:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $24
