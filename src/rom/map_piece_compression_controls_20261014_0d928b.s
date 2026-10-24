.setcpu "65816"
.segment "CODE"
.org $928B
map_control_0d928b:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
