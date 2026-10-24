.setcpu "65816"
.segment "CODE"
.org $D66F
map_control_0dd66f:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
