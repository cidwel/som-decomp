.setcpu "65816"
.segment "CODE"
.org $33BD
map_control_0d33bd:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
