.setcpu "65816"
.segment "CODE"
.org $819C
map_control_0d819c:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
