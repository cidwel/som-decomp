.setcpu "65816"
.segment "CODE"
.org $1351
map_control_0f1351:
    .byte $E8 ; backreference distance high bits
    .byte $6A ; distance low bit/count
