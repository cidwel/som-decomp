.setcpu "65816"
.segment "CODE"
.org $C6F4
map_control_0ec6f4:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
