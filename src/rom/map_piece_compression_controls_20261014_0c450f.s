.setcpu "65816"
.segment "CODE"
.org $450F
map_control_0c450f:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
