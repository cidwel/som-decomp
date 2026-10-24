.setcpu "65816"
.segment "CODE"
.org $52A1
map_control_0c52a1:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
