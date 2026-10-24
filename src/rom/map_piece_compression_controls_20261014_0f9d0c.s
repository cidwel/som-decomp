.setcpu "65816"
.segment "CODE"
.org $9D0C
map_control_0f9d0c:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
