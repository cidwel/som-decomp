.setcpu "65816"
.segment "CODE"
.org $0036
map_control_0e0036:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
