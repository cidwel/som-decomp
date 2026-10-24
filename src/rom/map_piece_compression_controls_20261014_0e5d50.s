.setcpu "65816"
.segment "CODE"
.org $5D50
map_control_0e5d50:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
