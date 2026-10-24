.setcpu "65816"
.segment "CODE"
.org $ED56
map_control_0eed56:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
