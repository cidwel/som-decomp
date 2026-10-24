.setcpu "65816"
.segment "CODE"
.org $E7FC
map_control_0de7fc:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
