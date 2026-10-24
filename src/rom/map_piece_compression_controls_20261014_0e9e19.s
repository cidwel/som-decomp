.setcpu "65816"
.segment "CODE"
.org $9E19
map_control_0e9e19:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
