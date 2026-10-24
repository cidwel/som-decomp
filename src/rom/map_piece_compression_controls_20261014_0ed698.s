.setcpu "65816"
.segment "CODE"
.org $D698
map_control_0ed698:
    .byte $E8 ; backreference distance high bits
    .byte $52 ; distance low bit/count
