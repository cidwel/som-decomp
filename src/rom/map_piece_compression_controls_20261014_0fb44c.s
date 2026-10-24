.setcpu "65816"
.segment "CODE"
.org $B44C
map_control_0fb44c:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
