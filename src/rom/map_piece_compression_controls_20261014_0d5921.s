.setcpu "65816"
.segment "CODE"
.org $5921
map_control_0d5921:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
