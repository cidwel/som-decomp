.setcpu "65816"
.segment "CODE"
.org $27ED
map_control_0d27ed:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
