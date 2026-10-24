.setcpu "65816"
.segment "CODE"
.org $E865
map_control_0fe865:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
