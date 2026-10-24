.setcpu "65816"
.segment "CODE"
.org $3698
map_control_0e3698:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
