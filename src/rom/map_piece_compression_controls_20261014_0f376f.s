.setcpu "65816"
.segment "CODE"
.org $376F
map_control_0f376f:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
