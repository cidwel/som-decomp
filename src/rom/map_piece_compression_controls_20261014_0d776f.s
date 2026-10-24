.setcpu "65816"
.segment "CODE"
.org $776F
map_control_0d776f:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
