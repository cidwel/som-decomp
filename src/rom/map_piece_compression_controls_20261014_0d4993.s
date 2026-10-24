.setcpu "65816"
.segment "CODE"
.org $4993
map_control_0d4993:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
