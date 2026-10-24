.setcpu "65816"
.segment "CODE"
.org $1E35
map_control_0f1e35:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
