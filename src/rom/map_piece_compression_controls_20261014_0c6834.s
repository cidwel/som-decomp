.setcpu "65816"
.segment "CODE"
.org $6834
map_control_0c6834:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
