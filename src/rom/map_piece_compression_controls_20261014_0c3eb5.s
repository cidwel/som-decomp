.setcpu "65816"
.segment "CODE"
.org $3EB5
map_control_0c3eb5:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
