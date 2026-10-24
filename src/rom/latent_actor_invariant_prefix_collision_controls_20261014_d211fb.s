; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $11FB
actor_collision_byte_d211fb:
    ; signed-XY-nibbles into actorCC collision box
    .byte $02
actor_collision_byte_d211fc:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $42
