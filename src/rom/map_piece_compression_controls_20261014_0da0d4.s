.setcpu "65816"
.segment "CODE"
.org $A0D4
map_control_0da0d4:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
