.setcpu "65816"
.segment "CODE"
.org $BCC3
map_control_0ebcc3:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
