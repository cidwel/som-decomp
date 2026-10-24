.setcpu "65816"
.segment "CODE"
.org $BED7
map_control_0ebed7:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
