.setcpu "65816"
.segment "CODE"
.org $2153
map_control_0d2153:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
