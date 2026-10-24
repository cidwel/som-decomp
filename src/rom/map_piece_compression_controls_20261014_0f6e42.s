.setcpu "65816"
.segment "CODE"
.org $6E42
map_control_0f6e42:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
