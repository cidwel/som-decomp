.setcpu "65816"
.segment "CODE"
.org $92B4
map_control_0c92b4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
