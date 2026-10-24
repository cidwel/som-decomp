.setcpu "65816"
.segment "CODE"
.org $E6D8
map_control_0fe6d8:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
