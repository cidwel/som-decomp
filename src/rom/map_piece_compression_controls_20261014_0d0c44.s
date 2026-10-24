.setcpu "65816"
.segment "CODE"
.org $0C44
map_control_0d0c44:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
