.setcpu "65816"
.segment "CODE"
.org $3B5C
map_control_0f3b5c:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
