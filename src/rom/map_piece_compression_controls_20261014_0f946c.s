.setcpu "65816"
.segment "CODE"
.org $946C
map_control_0f946c:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
