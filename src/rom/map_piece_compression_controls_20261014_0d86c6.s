.setcpu "65816"
.segment "CODE"
.org $86C6
map_control_0d86c6:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
