.setcpu "65816"
.segment "CODE"
.org $5BA3
map_control_0f5ba3:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
