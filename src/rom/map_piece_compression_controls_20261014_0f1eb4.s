.setcpu "65816"
.segment "CODE"
.org $1EB4
map_control_0f1eb4:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
