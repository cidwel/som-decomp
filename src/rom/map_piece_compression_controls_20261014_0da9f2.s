.setcpu "65816"
.segment "CODE"
.org $A9F2
map_control_0da9f2:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
