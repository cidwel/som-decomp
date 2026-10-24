.setcpu "65816"
.segment "CODE"
.org $D59C
map_control_0fd59c:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
