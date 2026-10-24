.setcpu "65816"
.segment "CODE"
.org $D68C
map_control_0dd68c:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
