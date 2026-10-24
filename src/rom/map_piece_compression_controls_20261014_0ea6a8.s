.setcpu "65816"
.segment "CODE"
.org $A6A8
map_control_0ea6a8:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
