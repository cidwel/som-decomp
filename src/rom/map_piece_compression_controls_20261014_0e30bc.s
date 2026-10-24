.setcpu "65816"
.segment "CODE"
.org $30BC
map_control_0e30bc:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
