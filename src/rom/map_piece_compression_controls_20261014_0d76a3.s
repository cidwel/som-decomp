.setcpu "65816"
.segment "CODE"
.org $76A3
map_control_0d76a3:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
