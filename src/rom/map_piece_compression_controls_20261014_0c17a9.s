.setcpu "65816"
.segment "CODE"
.org $17A9
map_control_0c17a9:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
