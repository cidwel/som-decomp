.setcpu "65816"
.segment "CODE"
.org $2E0E
map_control_0f2e0e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
