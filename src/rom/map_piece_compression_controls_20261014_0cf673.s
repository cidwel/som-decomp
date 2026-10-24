.setcpu "65816"
.segment "CODE"
.org $F673
map_control_0cf673:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
