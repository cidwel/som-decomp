.setcpu "65816"
.segment "CODE"
.org $6CF6
map_control_0c6cf6:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
