; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $299A
actor_collision_byte_d3299a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $01
actor_collision_byte_d3299b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $45
actor_collision_byte_d3299c:
    ; signed-XY-nibbles into actorCC collision box
    .byte $0D
actor_collision_byte_d3299d:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
