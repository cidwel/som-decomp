.setcpu "65816"
.segment "CODE"
.org $91AA
map_control_0c91aa:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
