.setcpu "65816"
.segment "CODE"
.org $9B18
map_control_0e9b18:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
