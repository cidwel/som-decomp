.setcpu "65816"
.segment "CODE"
.org $5557
map_control_0c5557:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
