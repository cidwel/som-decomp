.setcpu "65816"
.segment "CODE"
.org $9A4C
map_control_0d9a4c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
