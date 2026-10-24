.setcpu "65816"
.segment "CODE"
.org $24E2
map_control_0d24e2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
