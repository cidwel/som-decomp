.setcpu "65816"
.segment "CODE"
.org $B50A
map_control_0db50a:
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
