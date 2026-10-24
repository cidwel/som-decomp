.setcpu "65816"
.segment "CODE"
.org $D174
map_control_0fd174:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
