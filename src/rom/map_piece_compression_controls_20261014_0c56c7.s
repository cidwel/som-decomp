.setcpu "65816"
.segment "CODE"
.org $56C7
map_control_0c56c7:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
