.setcpu "65816"
.segment "CODE"
.org $277E
map_control_0f277e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
