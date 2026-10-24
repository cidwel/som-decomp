.setcpu "65816"
.segment "CODE"
.org $C849
map_control_0dc849:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
