.setcpu "65816"
.segment "CODE"
.org $8F78
map_control_0d8f78:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
