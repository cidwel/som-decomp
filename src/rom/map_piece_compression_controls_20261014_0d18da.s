.setcpu "65816"
.segment "CODE"
.org $18DA
map_control_0d18da:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
