.setcpu "65816"
.segment "CODE"
.org $78CB
map_control_0e78cb:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
