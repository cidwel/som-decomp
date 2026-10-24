.setcpu "65816"
.segment "CODE"
.org $92C7
map_control_0c92c7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
