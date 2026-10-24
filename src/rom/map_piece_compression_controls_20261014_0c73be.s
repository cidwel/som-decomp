.setcpu "65816"
.segment "CODE"
.org $73BE
map_control_0c73be:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
