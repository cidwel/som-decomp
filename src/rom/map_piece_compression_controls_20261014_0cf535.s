.setcpu "65816"
.segment "CODE"
.org $F535
map_control_0cf535:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
