.setcpu "65816"
.segment "CODE"
.org $814F
map_control_0f814f:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
