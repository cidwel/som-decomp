.setcpu "65816"
.segment "CODE"
.org $EE25
map_control_0fee25:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
