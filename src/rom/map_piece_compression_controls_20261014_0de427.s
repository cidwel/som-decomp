.setcpu "65816"
.segment "CODE"
.org $E427
map_control_0de427:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
