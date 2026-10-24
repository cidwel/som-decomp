.setcpu "65816"
.segment "CODE"
.org $F175
map_control_0cf175:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
