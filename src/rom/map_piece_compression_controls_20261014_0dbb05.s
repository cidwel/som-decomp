.setcpu "65816"
.segment "CODE"
.org $BB05
map_control_0dbb05:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
