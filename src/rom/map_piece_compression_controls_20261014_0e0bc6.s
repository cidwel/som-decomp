.setcpu "65816"
.segment "CODE"
.org $0BC6
map_control_0e0bc6:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
