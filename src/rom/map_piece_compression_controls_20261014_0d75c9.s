.setcpu "65816"
.segment "CODE"
.org $75C9
map_control_0d75c9:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
