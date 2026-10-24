.setcpu "65816"
.segment "CODE"
.org $7E0D
map_control_0c7e0d:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
