.setcpu "65816"
.segment "CODE"
.org $1E89
map_control_0d1e89:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
