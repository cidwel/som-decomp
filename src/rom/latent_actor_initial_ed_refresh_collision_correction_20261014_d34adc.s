; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4ADC
actor_collision_byte_d34adc:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $02
actor_collision_byte_d34add:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
actor_collision_byte_d34ade:
    ; signed-XY-nibbles into actorCC collision box
    .byte $03
actor_collision_byte_d34adf:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $66
