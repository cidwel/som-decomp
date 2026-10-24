.setcpu "65816"
.segment "CODE"
.org $D5AA
map_control_0fd5aa:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
