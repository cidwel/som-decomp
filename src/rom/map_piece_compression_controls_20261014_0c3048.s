.setcpu "65816"
.segment "CODE"
.org $3048
map_control_0c3048:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
