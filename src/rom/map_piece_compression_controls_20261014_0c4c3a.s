.setcpu "65816"
.segment "CODE"
.org $4C3A
map_control_0c4c3a:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
