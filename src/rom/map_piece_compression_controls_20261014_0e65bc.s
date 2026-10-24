.setcpu "65816"
.segment "CODE"
.org $65BC
map_control_0e65bc:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
