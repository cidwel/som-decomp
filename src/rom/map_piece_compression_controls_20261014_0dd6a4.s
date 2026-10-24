.setcpu "65816"
.segment "CODE"
.org $D6A4
map_control_0dd6a4:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
