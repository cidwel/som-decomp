.setcpu "65816"
.segment "CODE"
.org $D84D
map_control_0fd84d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
