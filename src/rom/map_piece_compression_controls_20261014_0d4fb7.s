.setcpu "65816"
.segment "CODE"
.org $4FB7
map_control_0d4fb7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
