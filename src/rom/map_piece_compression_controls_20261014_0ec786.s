.setcpu "65816"
.segment "CODE"
.org $C786
map_control_0ec786:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
