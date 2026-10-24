.setcpu "65816"
.segment "CODE"
.org $9CED
map_control_0f9ced:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
