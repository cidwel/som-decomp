.setcpu "65816"
.segment "CODE"
.org $FCB4
map_control_0dfcb4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
