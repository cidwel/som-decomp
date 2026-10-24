.setcpu "65816"
.segment "CODE"
.org $8FF8
map_control_0c8ff8:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
