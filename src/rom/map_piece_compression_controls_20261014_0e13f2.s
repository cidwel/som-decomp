.setcpu "65816"
.segment "CODE"
.org $13F2
map_control_0e13f2:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
