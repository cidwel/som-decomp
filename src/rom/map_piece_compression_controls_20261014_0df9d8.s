.setcpu "65816"
.segment "CODE"
.org $F9D8
map_control_0df9d8:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
