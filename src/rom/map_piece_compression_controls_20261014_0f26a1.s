.setcpu "65816"
.segment "CODE"
.org $26A1
map_control_0f26a1:
    .byte $E8 ; backreference distance high bits
    .byte $62 ; distance low bit/count
