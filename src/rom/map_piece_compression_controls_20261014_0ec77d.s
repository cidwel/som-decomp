.setcpu "65816"
.segment "CODE"
.org $C77D
map_control_0ec77d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
