.setcpu "65816"
.segment "CODE"
.org $1CB9
map_control_0e1cb9:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
