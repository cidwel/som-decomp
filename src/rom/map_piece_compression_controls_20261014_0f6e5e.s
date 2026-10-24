.setcpu "65816"
.segment "CODE"
.org $6E5E
map_control_0f6e5e:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
