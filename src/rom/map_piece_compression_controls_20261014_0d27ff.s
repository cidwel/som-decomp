.setcpu "65816"
.segment "CODE"
.org $27FF
map_control_0d27ff:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
