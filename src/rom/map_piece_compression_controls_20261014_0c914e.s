.setcpu "65816"
.segment "CODE"
.org $914E
map_control_0c914e:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
