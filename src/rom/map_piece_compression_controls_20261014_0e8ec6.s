.setcpu "65816"
.segment "CODE"
.org $8EC6
map_control_0e8ec6:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
