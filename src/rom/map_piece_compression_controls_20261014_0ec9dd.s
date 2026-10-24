.setcpu "65816"
.segment "CODE"
.org $C9DD
map_control_0ec9dd:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
