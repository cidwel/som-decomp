.setcpu "65816"
.segment "CODE"
.org $316D
map_control_0d316d:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
