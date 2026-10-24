.setcpu "65816"
.segment "CODE"
.org $9845
map_control_0f9845:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
