.setcpu "65816"
.segment "CODE"
.org $A04E
map_control_0da04e:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
