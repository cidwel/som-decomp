.setcpu "65816"
.segment "CODE"
.org $9DD9
map_control_0d9dd9:
    .byte $E8 ; backreference distance high bits
    .byte $48 ; distance low bit/count
