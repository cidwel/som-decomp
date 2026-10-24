.setcpu "65816"
.segment "CODE"
.org $D312
map_control_0ed312:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
