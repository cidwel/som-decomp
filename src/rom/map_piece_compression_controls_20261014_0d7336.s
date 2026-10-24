.setcpu "65816"
.segment "CODE"
.org $7336
map_control_0d7336:
    .byte $DA ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
