.setcpu "65816"
.segment "CODE"
.org $B1F7
map_control_0eb1f7:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
