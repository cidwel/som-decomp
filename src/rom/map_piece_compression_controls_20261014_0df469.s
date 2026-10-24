.setcpu "65816"
.segment "CODE"
.org $F469
map_control_0df469:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
