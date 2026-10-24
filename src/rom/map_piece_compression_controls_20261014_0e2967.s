.setcpu "65816"
.segment "CODE"
.org $2967
map_control_0e2967:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
