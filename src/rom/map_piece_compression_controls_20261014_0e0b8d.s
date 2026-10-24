.setcpu "65816"
.segment "CODE"
.org $0B8D
map_control_0e0b8d:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
