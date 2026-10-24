.setcpu "65816"
.segment "CODE"
.org $CD44
map_control_0fcd44:
    .byte $D1 ; same-value copy count/distance
