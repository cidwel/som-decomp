.setcpu "65816"
.segment "CODE"
.org $058C
map_control_0e058c:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
