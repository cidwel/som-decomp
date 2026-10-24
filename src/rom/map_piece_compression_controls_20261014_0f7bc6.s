.setcpu "65816"
.segment "CODE"
.org $7BC6
map_control_0f7bc6:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
