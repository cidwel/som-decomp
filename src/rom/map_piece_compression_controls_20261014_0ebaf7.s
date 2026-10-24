.setcpu "65816"
.segment "CODE"
.org $BAF7
map_control_0ebaf7:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
