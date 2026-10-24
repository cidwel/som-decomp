.setcpu "65816"
.segment "CODE"
.org $0935
map_control_0e0935:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
