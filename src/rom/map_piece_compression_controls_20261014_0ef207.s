.setcpu "65816"
.segment "CODE"
.org $F207
map_control_0ef207:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
