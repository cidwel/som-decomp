.setcpu "65816"
.segment "CODE"
.org $912F
map_control_0f912f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
