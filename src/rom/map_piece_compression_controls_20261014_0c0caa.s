.setcpu "65816"
.segment "CODE"
.org $0CAA
map_control_0c0caa:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
