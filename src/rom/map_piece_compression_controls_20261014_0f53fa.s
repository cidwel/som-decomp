.setcpu "65816"
.segment "CODE"
.org $53FA
map_control_0f53fa:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
