.setcpu "65816"
.segment "CODE"
.org $7900
map_control_0d7900:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
