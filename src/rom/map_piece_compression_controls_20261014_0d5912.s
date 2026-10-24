.setcpu "65816"
.segment "CODE"
.org $5912
map_control_0d5912:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
