.setcpu "65816"
.segment "CODE"
.org $6D90
map_control_0d6d90:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
