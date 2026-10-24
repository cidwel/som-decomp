.setcpu "65816"
.segment "CODE"
.org $1E26
map_control_0f1e26:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
