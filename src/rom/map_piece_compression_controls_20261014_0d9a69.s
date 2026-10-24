.setcpu "65816"
.segment "CODE"
.org $9A69
map_control_0d9a69:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
