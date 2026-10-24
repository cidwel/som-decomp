.setcpu "65816"
.segment "CODE"
.org $EEE8
map_control_0deee8:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
