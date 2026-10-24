.setcpu "65816"
.segment "CODE"
.org $9C70
map_control_0d9c70:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
