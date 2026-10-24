.setcpu "65816"
.segment "CODE"
.org $F7F3
map_control_0df7f3:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
