.setcpu "65816"
.segment "CODE"
.org $8832
map_control_0e8832:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
