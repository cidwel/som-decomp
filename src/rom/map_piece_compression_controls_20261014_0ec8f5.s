.setcpu "65816"
.segment "CODE"
.org $C8F5
map_control_0ec8f5:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
