.setcpu "65816"
.segment "CODE"
.org $E127
map_control_0de127:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
