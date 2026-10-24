.setcpu "65816"
.segment "CODE"
.org $0D7F
map_control_0e0d7f:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
