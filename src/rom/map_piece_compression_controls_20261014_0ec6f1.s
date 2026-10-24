.setcpu "65816"
.segment "CODE"
.org $C6F1
map_control_0ec6f1:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
