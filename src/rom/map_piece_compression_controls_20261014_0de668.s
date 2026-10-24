.setcpu "65816"
.segment "CODE"
.org $E668
map_control_0de668:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
