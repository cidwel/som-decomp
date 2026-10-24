.setcpu "65816"
.segment "CODE"
.org $CFF8
map_control_0ecff8:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
