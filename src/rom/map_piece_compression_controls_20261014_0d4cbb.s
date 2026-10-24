.setcpu "65816"
.segment "CODE"
.org $4CBB
map_control_0d4cbb:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
