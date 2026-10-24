.setcpu "65816"
.segment "CODE"
.org $09B9
map_control_0e09b9:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
