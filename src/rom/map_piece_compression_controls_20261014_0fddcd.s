.setcpu "65816"
.segment "CODE"
.org $DDCD
map_control_0fddcd:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
