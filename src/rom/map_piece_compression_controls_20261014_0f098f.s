.setcpu "65816"
.segment "CODE"
.org $098F
map_control_0f098f:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
