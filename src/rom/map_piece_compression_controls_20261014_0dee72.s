.setcpu "65816"
.segment "CODE"
.org $EE72
map_control_0dee72:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
