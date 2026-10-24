.setcpu "65816"
.segment "CODE"
.org $B703
map_control_0eb703:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
