.setcpu "65816"
.segment "CODE"
.org $BF29
map_control_0ebf29:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
