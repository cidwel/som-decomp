.setcpu "65816"
.segment "CODE"
.org $B749
map_control_0eb749:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
