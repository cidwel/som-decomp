.setcpu "65816"
.segment "CODE"
.org $308E
map_control_0f308e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
