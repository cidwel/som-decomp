.setcpu "65816"
.segment "CODE"
.org $1863
map_control_0f1863:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
