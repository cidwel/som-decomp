.setcpu "65816"
.segment "CODE"
.org $1E97
map_control_0f1e97:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
