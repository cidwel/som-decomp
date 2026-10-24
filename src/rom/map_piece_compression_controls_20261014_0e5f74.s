.setcpu "65816"
.segment "CODE"
.org $5F74
map_control_0e5f74:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
