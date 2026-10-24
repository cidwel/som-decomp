.setcpu "65816"
.segment "CODE"
.org $BF8C
map_control_0ebf8c:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
