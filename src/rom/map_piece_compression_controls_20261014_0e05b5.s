.setcpu "65816"
.segment "CODE"
.org $05B5
map_control_0e05b5:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
