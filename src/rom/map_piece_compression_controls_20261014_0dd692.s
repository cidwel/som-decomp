.setcpu "65816"
.segment "CODE"
.org $D692
map_control_0dd692:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
