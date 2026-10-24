.setcpu "65816"
.segment "CODE"
.org $CD86
map_control_0dcd86:
    .byte $C1 ; same-value copy count/distance
