.setcpu "65816"
.segment "CODE"
.org $2935
map_control_0d2935:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
