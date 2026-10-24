.setcpu "65816"
.segment "CODE"
.org $9A2E
map_control_0f9a2e:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
