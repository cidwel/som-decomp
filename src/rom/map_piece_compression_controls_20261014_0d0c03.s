.setcpu "65816"
.segment "CODE"
.org $0C03
map_control_0d0c03:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
