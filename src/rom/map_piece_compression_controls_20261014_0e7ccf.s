.setcpu "65816"
.segment "CODE"
.org $7CCF
map_control_0e7ccf:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
