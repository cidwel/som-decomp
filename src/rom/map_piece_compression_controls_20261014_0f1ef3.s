.setcpu "65816"
.segment "CODE"
.org $1EF3
map_control_0f1ef3:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
