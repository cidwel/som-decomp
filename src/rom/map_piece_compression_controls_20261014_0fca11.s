.setcpu "65816"
.segment "CODE"
.org $CA11
map_control_0fca11:
    .byte $C6 ; same-value copy count/distance
