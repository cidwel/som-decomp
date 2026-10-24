.setcpu "65816"
.segment "CODE"
.org $1DA8
map_control_0d1da8:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
