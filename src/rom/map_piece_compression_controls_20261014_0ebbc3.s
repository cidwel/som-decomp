.setcpu "65816"
.segment "CODE"
.org $BBC3
map_control_0ebbc3:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
