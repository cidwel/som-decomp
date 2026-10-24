.setcpu "65816"
.segment "CODE"
.org $4BDD
map_control_0e4bdd:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
