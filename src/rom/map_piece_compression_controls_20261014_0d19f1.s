.setcpu "65816"
.segment "CODE"
.org $19F1
map_control_0d19f1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
