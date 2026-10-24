.setcpu "65816"
.segment "CODE"
.org $1C69
map_control_0f1c69:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
