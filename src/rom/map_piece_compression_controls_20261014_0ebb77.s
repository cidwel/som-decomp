.setcpu "65816"
.segment "CODE"
.org $BB77
map_control_0ebb77:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
