.setcpu "65816"
.segment "CODE"
.org $64BA
map_control_0d64ba:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
