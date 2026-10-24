.setcpu "65816"
.segment "CODE"
.org $424F
map_control_0d424f:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
