; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $475A
actor_collision_byte_d3475a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3475b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d3475c:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d3475d:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
