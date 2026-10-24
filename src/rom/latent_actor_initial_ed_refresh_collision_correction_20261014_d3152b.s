; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $152B
actor_collision_byte_d3152b:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E0
actor_collision_byte_d3152c:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d3152d:
    ; signed-XY-nibbles into actorCC collision box
    .byte $20
actor_collision_byte_d3152e:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $24
