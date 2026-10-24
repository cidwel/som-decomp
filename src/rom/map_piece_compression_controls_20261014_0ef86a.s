.setcpu "65816"
.segment "CODE"
.org $F86A
map_control_0ef86a:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
