.setcpu "65816"
.segment "CODE"
.org $FCF7
map_control_0efcf7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
