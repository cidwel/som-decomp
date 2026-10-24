.setcpu "65816"
.segment "CODE"
.org $A6E5
map_control_0ea6e5:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
