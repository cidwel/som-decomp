.setcpu "65816"
.segment "CODE"
.org $173A
map_control_0d173a:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
