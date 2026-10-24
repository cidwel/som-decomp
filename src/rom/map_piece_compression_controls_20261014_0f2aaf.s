.setcpu "65816"
.segment "CODE"
.org $2AAF
map_control_0f2aaf:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
