.setcpu "65816"
.segment "CODE"
.org $4F1A
map_control_0d4f1a:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
