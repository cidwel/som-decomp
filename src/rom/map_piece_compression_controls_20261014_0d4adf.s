.setcpu "65816"
.segment "CODE"
.org $4ADF
map_control_0d4adf:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
