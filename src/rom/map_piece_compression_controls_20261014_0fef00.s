.setcpu "65816"
.segment "CODE"
.org $EF00
map_control_0fef00:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
