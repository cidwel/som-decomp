.setcpu "65816"
.segment "CODE"
.org $1C81
map_control_0f1c81:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
