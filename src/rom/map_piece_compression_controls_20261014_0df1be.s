.setcpu "65816"
.segment "CODE"
.org $F1BE
map_control_0df1be:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
