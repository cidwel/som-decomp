.setcpu "65816"
.segment "CODE"
.org $D585
map_control_0fd585:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
