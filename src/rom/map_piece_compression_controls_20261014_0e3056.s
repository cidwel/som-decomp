.setcpu "65816"
.segment "CODE"
.org $3056
map_control_0e3056:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
