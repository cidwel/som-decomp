.setcpu "65816"
.segment "CODE"
.org $3F3F
map_control_0d3f3f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
