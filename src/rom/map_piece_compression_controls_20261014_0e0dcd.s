.setcpu "65816"
.segment "CODE"
.org $0DCD
map_control_0e0dcd:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
