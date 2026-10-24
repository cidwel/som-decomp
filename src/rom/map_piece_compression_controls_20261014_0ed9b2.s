.setcpu "65816"
.segment "CODE"
.org $D9B2
map_control_0ed9b2:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
