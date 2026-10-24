.setcpu "65816"
.segment "CODE"
.org $3F38
map_control_0f3f38:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
