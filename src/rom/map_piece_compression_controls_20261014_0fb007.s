.setcpu "65816"
.segment "CODE"
.org $B007
map_control_0fb007:
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
