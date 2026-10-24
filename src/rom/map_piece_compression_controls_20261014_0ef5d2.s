.setcpu "65816"
.segment "CODE"
.org $F5D2
map_control_0ef5d2:
    .byte $E8 ; backreference distance high bits
    .byte $5E ; distance low bit/count
