.setcpu "65816"
.segment "CODE"
.org $F380
map_control_0cf380:
    .byte $CD ; same-value copy count/distance
