.setcpu "65816"
.segment "CODE"
.org $A01E
map_control_0da01e:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
