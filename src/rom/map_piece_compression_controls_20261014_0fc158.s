.setcpu "65816"
.segment "CODE"
.org $C158
map_control_0fc158:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
