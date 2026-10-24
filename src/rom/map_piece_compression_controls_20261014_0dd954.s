.setcpu "65816"
.segment "CODE"
.org $D954
map_control_0dd954:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
