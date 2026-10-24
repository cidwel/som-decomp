.setcpu "65816"
.segment "CODE"
.org $CFC3
map_control_0ecfc3:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
