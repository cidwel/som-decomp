.setcpu "65816"
.segment "CODE"
.org $4528
map_control_0d4528:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
