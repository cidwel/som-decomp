.setcpu "65816"
.segment "CODE"
.org $0F69
map_control_0e0f69:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
