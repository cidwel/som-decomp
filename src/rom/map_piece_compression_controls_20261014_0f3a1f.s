.setcpu "65816"
.segment "CODE"
.org $3A1F
map_control_0f3a1f:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
