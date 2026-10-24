.setcpu "65816"
.segment "CODE"
.org $61F4
map_control_0e61f4:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
