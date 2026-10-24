.setcpu "65816"
.segment "CODE"
.org $1C70
map_control_0d1c70:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
