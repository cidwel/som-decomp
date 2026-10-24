.setcpu "65816"
.segment "CODE"
.org $F180
map_control_0cf180:
    .byte $C4 ; same-value copy count/distance
