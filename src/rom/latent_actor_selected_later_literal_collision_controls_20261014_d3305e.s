; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $305E
actor_collision_byte_d3305e:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $02
actor_collision_byte_d3305f:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
