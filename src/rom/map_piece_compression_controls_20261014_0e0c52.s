.setcpu "65816"
.segment "CODE"
.org $0C52
map_control_0e0c52:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
