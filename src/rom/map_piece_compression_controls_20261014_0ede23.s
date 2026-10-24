.setcpu "65816"
.segment "CODE"
.org $DE23
map_control_0ede23:
    .byte $EA ; backreference distance high bits
    .byte $86 ; distance low bit/count
