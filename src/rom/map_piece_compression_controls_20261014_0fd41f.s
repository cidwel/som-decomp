.setcpu "65816"
.segment "CODE"
.org $D41F
map_control_0fd41f:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
