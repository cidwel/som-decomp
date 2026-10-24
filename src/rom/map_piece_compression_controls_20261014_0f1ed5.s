.setcpu "65816"
.segment "CODE"
.org $1ED5
map_control_0f1ed5:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
