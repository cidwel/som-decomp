.setcpu "65816"
.segment "CODE"
.org $58A4
map_control_0c58a4:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
