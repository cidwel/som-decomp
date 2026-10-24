.setcpu "65816"
.segment "CODE"
.org $A940
map_control_0da940:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
