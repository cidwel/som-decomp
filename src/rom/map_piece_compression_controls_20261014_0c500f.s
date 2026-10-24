.setcpu "65816"
.segment "CODE"
.org $500F
map_control_0c500f:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
