.setcpu "65816"
.segment "CODE"
.org $3140
map_control_0d3140:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
