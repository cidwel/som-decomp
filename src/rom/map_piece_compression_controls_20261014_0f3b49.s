.setcpu "65816"
.segment "CODE"
.org $3B49
map_control_0f3b49:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
