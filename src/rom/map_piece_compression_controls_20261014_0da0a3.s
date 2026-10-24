.setcpu "65816"
.segment "CODE"
.org $A0A3
map_control_0da0a3:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
