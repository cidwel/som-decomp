.setcpu "65816"
.segment "CODE"
.org $4740
map_control_0c4740:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
