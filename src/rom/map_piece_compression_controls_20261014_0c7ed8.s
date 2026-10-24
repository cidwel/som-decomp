.setcpu "65816"
.segment "CODE"
.org $7ED8
map_control_0c7ed8:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
