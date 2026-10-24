.setcpu "65816"
.segment "CODE"
.org $7EF1
map_control_0c7ef1:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
