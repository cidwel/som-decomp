.setcpu "65816"
.segment "CODE"
.org $63A8
map_control_0f63a8:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
