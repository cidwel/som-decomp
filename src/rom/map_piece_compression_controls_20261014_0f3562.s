.setcpu "65816"
.segment "CODE"
.org $3562
map_control_0f3562:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
