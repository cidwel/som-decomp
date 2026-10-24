.setcpu "65816"
.segment "CODE"
.org $10F5
map_control_0e10f5:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
