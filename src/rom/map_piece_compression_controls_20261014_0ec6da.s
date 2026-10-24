.setcpu "65816"
.segment "CODE"
.org $C6DA
map_control_0ec6da:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
