.setcpu "65816"
.segment "CODE"
.org $968D
map_control_0e968d:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
