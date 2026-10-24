.setcpu "65816"
.segment "CODE"
.org $7D40
map_control_0c7d40:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
