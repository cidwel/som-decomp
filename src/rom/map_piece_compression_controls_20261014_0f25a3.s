.setcpu "65816"
.segment "CODE"
.org $25A3
map_control_0f25a3:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
