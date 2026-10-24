.setcpu "65816"
.segment "CODE"
.org $2BCD
map_control_0d2bcd:
    .byte $C9 ; same-value copy count/distance
