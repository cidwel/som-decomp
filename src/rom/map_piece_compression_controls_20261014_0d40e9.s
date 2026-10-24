.setcpu "65816"
.segment "CODE"
.org $40E9
map_control_0d40e9:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
