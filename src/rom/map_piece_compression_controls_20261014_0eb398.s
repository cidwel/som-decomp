.setcpu "65816"
.segment "CODE"
.org $B398
map_control_0eb398:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
