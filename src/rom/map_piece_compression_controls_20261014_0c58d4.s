.setcpu "65816"
.segment "CODE"
.org $58D4
map_control_0c58d4:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
