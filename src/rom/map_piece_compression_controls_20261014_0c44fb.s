.setcpu "65816"
.segment "CODE"
.org $44FB
map_control_0c44fb:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
