.setcpu "65816"
.segment "CODE"
.org $4BEE
map_control_0c4bee:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
