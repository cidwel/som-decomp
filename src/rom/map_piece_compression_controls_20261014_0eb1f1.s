.setcpu "65816"
.segment "CODE"
.org $B1F1
map_control_0eb1f1:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
