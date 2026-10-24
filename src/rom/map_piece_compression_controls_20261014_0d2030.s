.setcpu "65816"
.segment "CODE"
.org $2030
map_control_0d2030:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
