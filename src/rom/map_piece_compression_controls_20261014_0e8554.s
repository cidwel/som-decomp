.setcpu "65816"
.segment "CODE"
.org $8554
map_control_0e8554:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
