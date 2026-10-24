.setcpu "65816"
.segment "CODE"
.org $D665
map_control_0dd665:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
