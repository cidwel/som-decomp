.setcpu "65816"
.segment "CODE"
.org $9412
map_control_0f9412:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
