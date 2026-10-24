.setcpu "65816"
.segment "CODE"
.org $73AF
map_control_0c73af:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
