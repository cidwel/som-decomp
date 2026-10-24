.setcpu "65816"
.segment "CODE"
.org $933A
map_control_0e933a:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
