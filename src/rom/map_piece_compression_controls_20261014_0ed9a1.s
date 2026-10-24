.setcpu "65816"
.segment "CODE"
.org $D9A1
map_control_0ed9a1:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
