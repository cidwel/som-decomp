; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $169A
actor_collision_byte_d3169a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d3169b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
actor_collision_byte_d3169c:
    ; signed-XY-nibbles into actorCC collision box
    .byte $F1
actor_collision_byte_d3169d:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
