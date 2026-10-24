.setcpu "65816"
.segment "CODE"
.org $CE1D
map_control_0fce1d:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
