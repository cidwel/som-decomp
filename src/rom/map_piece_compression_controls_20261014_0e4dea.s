.setcpu "65816"
.segment "CODE"
.org $4DEA
map_control_0e4dea:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $D4 ; same-value copy count/distance
