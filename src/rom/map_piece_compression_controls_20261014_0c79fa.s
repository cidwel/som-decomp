.setcpu "65816"
.segment "CODE"
.org $79FA
map_control_0c79fa:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
