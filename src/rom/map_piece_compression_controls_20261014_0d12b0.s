.setcpu "65816"
.segment "CODE"
.org $12B0
map_control_0d12b0:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
