.setcpu "65816"
.segment "CODE"
.org $428B
map_control_0d428b:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
