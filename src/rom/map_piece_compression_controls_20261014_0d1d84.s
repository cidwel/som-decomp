.setcpu "65816"
.segment "CODE"
.org $1D84
map_control_0d1d84:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
