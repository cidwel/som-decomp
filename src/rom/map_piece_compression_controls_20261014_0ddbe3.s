.setcpu "65816"
.segment "CODE"
.org $DBE3
map_control_0ddbe3:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
