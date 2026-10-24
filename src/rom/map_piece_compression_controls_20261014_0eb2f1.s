.setcpu "65816"
.segment "CODE"
.org $B2F1
map_control_0eb2f1:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
