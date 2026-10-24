.setcpu "65816"
.segment "CODE"
.org $25B9
map_control_0e25b9:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
