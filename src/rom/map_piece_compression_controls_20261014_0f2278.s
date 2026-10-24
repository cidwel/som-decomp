.setcpu "65816"
.segment "CODE"
.org $2278
map_control_0f2278:
    .byte $EA ; backreference distance high bits
    .byte $8D ; distance low bit/count
