.setcpu "65816"
.segment "CODE"
.org $967B
map_control_0d967b:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
