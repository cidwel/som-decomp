.setcpu "65816"
.segment "CODE"
.org $9137
map_control_0c9137:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
