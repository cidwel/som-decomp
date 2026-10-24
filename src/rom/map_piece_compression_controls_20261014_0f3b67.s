.setcpu "65816"
.segment "CODE"
.org $3B67
map_control_0f3b67:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
