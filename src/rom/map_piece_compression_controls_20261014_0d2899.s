.setcpu "65816"
.segment "CODE"
.org $2899
map_control_0d2899:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
