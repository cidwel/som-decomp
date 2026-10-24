.setcpu "65816"
.segment "CODE"
.org $0B71
map_control_0e0b71:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
