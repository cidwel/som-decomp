.setcpu "65816"
.segment "CODE"
.org $63F1
map_control_0d63f1:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
