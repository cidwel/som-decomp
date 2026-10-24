.setcpu "65816"
.segment "CODE"
.org $EB1B
map_control_0feb1b:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
