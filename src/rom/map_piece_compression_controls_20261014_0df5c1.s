.setcpu "65816"
.segment "CODE"
.org $F5C1
map_control_0df5c1:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
