.setcpu "65816"
.segment "CODE"
.org $09FF
map_control_0f09ff:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
