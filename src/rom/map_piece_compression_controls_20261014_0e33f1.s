.setcpu "65816"
.segment "CODE"
.org $33F1
map_control_0e33f1:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
