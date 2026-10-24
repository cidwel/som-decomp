.setcpu "65816"
.segment "CODE"
.org $6F78
map_control_0e6f78:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
