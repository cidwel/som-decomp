.setcpu "65816"
.segment "CODE"
.org $3F48
map_control_0f3f48:
    .byte $EA ; backreference distance high bits
    .byte $86 ; distance low bit/count
