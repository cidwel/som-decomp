.setcpu "65816"
.segment "CODE"
.org $D9AC
map_control_0ed9ac:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
