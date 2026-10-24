.setcpu "65816"
.segment "CODE"
.org $4D1E
map_control_0d4d1e:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
