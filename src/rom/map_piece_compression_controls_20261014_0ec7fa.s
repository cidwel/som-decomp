.setcpu "65816"
.segment "CODE"
.org $C7FA
map_control_0ec7fa:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
