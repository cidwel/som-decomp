.setcpu "65816"
.segment "CODE"
.org $9D2A
map_control_0f9d2a:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
