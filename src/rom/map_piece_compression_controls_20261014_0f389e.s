.setcpu "65816"
.segment "CODE"
.org $389E
map_control_0f389e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
