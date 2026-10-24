.setcpu "65816"
.segment "CODE"
.org $44BC
map_control_0d44bc:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
