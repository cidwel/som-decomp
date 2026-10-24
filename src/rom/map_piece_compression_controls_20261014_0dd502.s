.setcpu "65816"
.segment "CODE"
.org $D502
map_control_0dd502:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
