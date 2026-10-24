.setcpu "65816"
.segment "CODE"
.org $9D8C
map_control_0d9d8c:
    .byte $E8 ; backreference distance high bits
    .byte $33 ; distance low bit/count
