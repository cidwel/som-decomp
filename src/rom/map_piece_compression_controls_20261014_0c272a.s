.setcpu "65816"
.segment "CODE"
.org $272A
map_control_0c272a:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
