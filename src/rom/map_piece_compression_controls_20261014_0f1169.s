.setcpu "65816"
.segment "CODE"
.org $1169
map_control_0f1169:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
