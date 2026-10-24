.setcpu "65816"
.segment "CODE"
.org $2561
map_control_0f2561:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
