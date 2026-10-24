.setcpu "65816"
.segment "CODE"
.org $3B00
map_control_0f3b00:
    .byte $EA ; backreference distance high bits
    .byte $86 ; distance low bit/count
