.setcpu "65816"
.segment "CODE"
.org $7B59
map_control_0e7b59:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
